#ifndef LEG_KILO_GLOG_UTILS_HPP
#define LEG_KILO_GLOG_UTILS_HPP

#include <string>

// ---------------------------------------------------------------------
// glog / gflags 가 있으면 사용, 없으면 안전한 스텁으로 대체
// ---------------------------------------------------------------------
#if __has_include(<glog/logging.h>)
  #include <glog/logging.h>
  #define LEGKILO_HAVE_GLOG 1
#else
  #define LEGKILO_HAVE_GLOG 0
#endif

namespace legkilo {

// ---------------------------------------------------------------------
// Logging: 프로젝트에서 사용하는 간단 래퍼
//  - 기존 코드: std::unique_ptr<legkilo::Logging> logging(new legkilo::Logging(argc, argv, "logs"));
//               logging->flushLogFiles();
// ---------------------------------------------------------------------
class Logging {
public:
  Logging(int argc, char** argv, const std::string& log_dir) {
#if LEGKILO_HAVE_GLOG
    (void)argc; (void)argv;
    google::InitGoogleLogging(argv ? argv[0] : "leg_kilo");

    // 표준 에러로 INFO 이상 출력
    google::SetStderrLogging(google::GLOG_INFO);

    // 로그 파일 목적지 설정 (옵션)
    if (!log_dir.empty()) {
      // 각 레벨 별 파일 prefix 지정 (glog는 prefix로 파일을 생성함)
      google::SetLogDestination(google::GLOG_INFO,  (log_dir + "/INFO_").c_str());
      google::SetLogDestination(google::GLOG_WARNING,(log_dir + "/WARN_").c_str());
      google::SetLogDestination(google::GLOG_ERROR,  (log_dir + "/ERROR_").c_str());
      google::SetLogDestination(google::GLOG_FATAL,  (log_dir + "/FATAL_").c_str());
    }
#else
    (void)argc; (void)argv; (void)log_dir;
#endif
  }

  ~Logging() {
#if LEGKILO_HAVE_GLOG
    google::ShutdownGoogleLogging();
#endif
  }

  inline void flushLogFiles() {
#if LEGKILO_HAVE_GLOG
    google::FlushLogFiles(google::GLOG_INFO);
    google::FlushLogFiles(google::GLOG_WARNING);
    google::FlushLogFiles(google::GLOG_ERROR);
    google::FlushLogFiles(google::GLOG_FATAL);
#endif
  }
};

} // namespace legkilo

// ---------------------------------------------------------------------
// 스텁 매크로들 (glog 미존재 시에도 LOG(...) 사용 가능하게)
//  - 기존 코드 호환: LOG(INFO) << "msg";
//  - FATAL은 스텁에서 단순 출력(필요하면 std::abort()로 바꿔도 됨)
// ---------------------------------------------------------------------
#if !LEGKILO_HAVE_GLOG
  #include <iostream>
  #include <sstream>
  namespace legkilo::glog_stub {
    struct LogStream {
      std::ostringstream oss;
      template <typename T>
      LogStream& operator<<(const T& v) { oss << v; return *this; }
      ~LogStream() { std::cerr << oss.str() << std::endl; }
    };
    struct FatalStream {
      std::ostringstream oss;
      template <typename T>
      FatalStream& operator<<(const T& v) { oss << v; return *this; }
      ~FatalStream() {
        std::cerr << "[FATAL] " << oss.str() << std::endl;
        // std::abort(); // 필요시 활성화
      }
    };
    inline LogStream make_log()   { return LogStream(); }
    inline FatalStream make_fatal(){ return FatalStream(); }
  } // namespace legkilo::glog_stub

  // glog와 유사한 인터페이스
  // 사용 예: LOG(INFO) << "hello";
  #define INFO    info
  #define WARNING warning
  #define ERROR   error
  #define FATAL   fatal

  // FATAL만 별도 핸들링
  #define LOG(level) \
      (std::string(#level) == std::string("fatal") ? ::legkilo::glog_stub::make_fatal() \
                                                   : ::legkilo::glog_stub::make_log())

  // CHECK/ASSERT 류 간단 스텁
  #ifndef CHECK
    #define CHECK(expr) \
      if(!(expr)) ::legkilo::glog_stub::make_fatal() << "CHECK failed: " #expr
  #endif
  #ifndef CHECK_EQ
    #define CHECK_EQ(a,b) CHECK((a)==(b))
  #endif
  #ifndef CHECK_NE
    #define CHECK_NE(a,b) CHECK((a)!=(b))
  #endif
  #ifndef CHECK_LT
    #define CHECK_LT(a,b) CHECK((a)<(b))
  #endif
  #ifndef CHECK_LE
    #define CHECK_LE(a,b) CHECK((a)<=(b))
  #endif
  #ifndef CHECK_GT
    #define CHECK_GT(a,b) CHECK((a)>(b))
  #endif
  #ifndef CHECK_GE
    #define CHECK_GE(a,b) CHECK((a)>=(b))
  #endif

#else
  // glog가 있을 때는 glog 매크로를 그대로 사용
  // (LOG, CHECK, CHECK_*, VLOG 등 glog에서 제공)
#endif

#endif // LEG_KILO_GLOG_UTILS_HPP

