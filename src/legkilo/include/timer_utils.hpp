#ifndef LEG_KILO_TIMER_UTILS_HPP
#define LEG_KILO_TIMER_UTILS_HPP

#include <chrono>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <mutex>
#include <limits>
#include <iostream>
#include <iomanip>

#include "glog_utils.hpp"  // LOG(...) 사용. glog 없으면 스텁이 출력 처리

namespace legkilo {

/**
 * @brief 간단한 구간 타이머(헤더 온리)
 *  - TIC/TOC 또는 RAII(ScopedTimer)로 사용
 *  - 평균/최대/누적 시간(ms)과 호출 회수 집계
 *  - 멀티스레드 안전
 *
 * 사용 예:
 *   Timer::tic("eskf_update");
 *   ... 작업 ...
 *   Timer::toc("eskf_update");
 *
 *   {
 *     ScopedTimer t("voxel_insert");  // 블록 종료 시 자동 집계
 *     ... 작업 ...
 *   }
 *
 *   Timer::logAllAverTime();  // 전체 통계 로그
 */
class Timer {
public:
  using clock      = std::chrono::steady_clock;
  using time_point = clock::time_point;
  using duration   = std::chrono::duration<double, std::milli>; // ms

  struct Stats {
    double  last_ms   = 0.0;
    double  total_ms  = 0.0;
    double  max_ms    = 0.0;
    double  min_ms    = std::numeric_limits<double>::infinity();
    uint64_t count    = 0;

    double avg_ms() const {
      return (count == 0) ? 0.0 : (total_ms / static_cast<double>(count));
    }
  };

  // 구간 시작
  static void tic(const std::string& key) {
    std::lock_guard<std::mutex> lk(mtx());
    starts()[key] = clock::now();
  }

  // 구간 종료 + 집계 (선택: work 단위 지정 → 평균/Throughput 계산에 사용할 수 있음)
  static double toc(const std::string& key, double /*work_units*/ = 1.0) {
    time_point t1 = clock::now();
    std::lock_guard<std::mutex> lk(mtx());

    auto it = starts().find(key);
    if (it == starts().end()) {
      // tic 없이 toc가 호출된 경우
      return 0.0;
    }

    double dt_ms = std::chrono::duration_cast<duration>(t1 - it->second).count();
    auto& s = stats()[key];
    s.last_ms  = dt_ms;
    s.total_ms += dt_ms;
    s.count    += 1;
    if (dt_ms > s.max_ms) s.max_ms = dt_ms;
    if (dt_ms < s.min_ms) s.min_ms = dt_ms;

    // 시작 기록 제거(다음 루프 대비)
    starts().erase(it);
    return dt_ms;
  }

  // 특정 키 통계 읽기
  static Stats get(const std::string& key) {
    std::lock_guard<std::mutex> lk(mtx());
    auto it = stats().find(key);
    return (it == stats().end()) ? Stats{} : it->second;
  }

  // 전체 초기화
  static void resetAll() {
    std::lock_guard<std::mutex> lk(mtx());
    stats().clear();
    starts().clear();
  }

  // 전체 통계 로그 출력
  static void logAllAverTime() {
    std::lock_guard<std::mutex> lk(mtx());
    if (stats().empty()) {
      LOG(INFO) << "[Timer] no entries";
      return;
    }

    // 보기 좋게 정렬해 출력
    std::ostringstream oss;
    oss << "\n[Timer] ---- aggregated ----\n"
        << std::left << std::setw(28) << "name"
        << std::right << std::setw(10) << "avg(ms)"
        << std::setw(10) << "last"
        << std::setw(10) << "min"
        << std::setw(10) << "max"
        << std::setw(12) << "count"
        << "\n";

    for (const auto& kv : stats()) {
      const auto& name = kv.first;
      const auto& s    = kv.second;
      oss << std::left  << std::setw(28) << name
          << std::right << std::setw(10) << std::fixed << std::setprecision(3) << s.avg_ms()
          << std::setw(10) << s.last_ms
          << std::setw(10) << (s.count ? s.min_ms : 0.0)
          << std::setw(10) << s.max_ms
          << std::setw(12) << s.count
          << "\n";
    }
    LOG(INFO) << oss.str();
  }

private:
  // 내부 저장소 (정적 싱글턴)
  static std::unordered_map<std::string, time_point>& starts() {
    static std::unordered_map<std::string, time_point> s;
    return s;
  }
  static std::unordered_map<std::string, Stats>& stats() {
    static std::unordered_map<std::string, Stats> s;
    return s;
  }
  static std::mutex& mtx() {
    static std::mutex m;
    return m;
  }
};

// RAII 편의 클래스: 생성 시 tic, 소멸 시 toc
class ScopedTimer {
public:
  explicit ScopedTimer(std::string key) : key_(std::move(key)) {
    Timer::tic(key_);
  }
  ~ScopedTimer() {
    Timer::toc(key_);
  }
private:
  std::string key_;
};

// 매크로 편의 (디버그 컴파일에서만 쓰고 싶다면 #ifdef NDEBUG 등으로 감싸도 됨)
#define LEGKILO_TIC(name_str)  ::legkilo::Timer::tic(name_str)
#define LEGKILO_TOC(name_str)  ::legkilo::Timer::toc(name_str)

} // namespace legkilo

#endif // LEG_KILO_TIMER_UTILS_HPP

