#ifndef LEG_KILO_STATE_INITIAL_HPP
#define LEG_KILO_STATE_INITIAL_HPP

#include <vector>
#include <numeric>
#include <cmath>

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace legkilo {
namespace state {

/**
 * @brief 초기화 파라미터
 *  - g_norm: 중력 크기 (m/s^2)
 *  - init_yaw_rad: 초기 yaw(선택). 기본 0.
 */
struct InitParams {
  double g_norm      = 9.81;
  double init_yaw_rad = 0.0;
};

/**
 * @brief 필터/추정의 초기 상태 컨테이너
 *  - T_wb:   world←body 변환 (SE3)
 *  - v_wb:   world 기준 선속도
 *  - ba/bg:  가속/자이로 바이어스
 *  - grav_w: world 기준 중력 벡터 (보통 [0,0,-g])
 *  - timestamp: 초기 타임스탬프(초) — 필요 시 세팅
 */
struct InitialState {
  Eigen::Isometry3d T_wb = Eigen::Isometry3d::Identity(); // R|t
  Eigen::Vector3d   v_wb = Eigen::Vector3d::Zero();
  Eigen::Vector3d   ba   = Eigen::Vector3d::Zero();
  Eigen::Vector3d   bg   = Eigen::Vector3d::Zero();
  Eigen::Vector3d   grav_w = Eigen::Vector3d(0, 0, -9.81);
  double            timestamp = 0.0;
};

/**
 * @brief 기본 초기 상태 생성
 *  - R = Rz(init_yaw), t = 0
 *  - v = 0, ba/bg = 0
 *  - grav_w = [0,0,-g_norm]
 */
inline InitialState makeDefault(const InitParams& p = {}) {
  InitialState s;
  const double cy = std::cos(p.init_yaw_rad), sy = std::sin(p.init_yaw_rad);
  Eigen::Matrix3d Rz; Rz << cy, -sy, 0,
                            sy,  cy, 0,
                             0,   0, 1;
  s.T_wb.linear() = Rz;
  s.T_wb.translation().setZero();
  s.v_wb.setZero();
  s.ba.setZero();
  s.bg.setZero();
  s.grav_w = Eigen::Vector3d(0, 0, -p.g_norm);
  s.timestamp = 0.0;
  return s;
}

/**
 * @brief 정지 상태에서 수집한 IMU 가속도 샘플(바디 프레임)을 이용해 중력 크기/방향을 보정
 *  - 주의: 바디→월드의 Yaw를 알 수 없으므로, 여기서는 grav_w의 크기만 신뢰하고
 *          방향은 [0,0,-g]로 둡니다(기본 좌표계). yaw는 InitParams로만 설정.
 *  - 실제 정렬(roll/pitch)을 바디 샘플에서 바로 world로 옮기려면 바디의 기준자세 정의가 필요하므로
 *    헤더 유틸에서는 보수적으로 magnitude만 씁니다. (필요하면 .cc에서 확장)
 */
inline InitialState makeFromAccSamples(const std::vector<Eigen::Vector3d>& acc_body_samples,
                                       const InitParams& p = {}) {
  InitialState s = makeDefault(p);

  if (!acc_body_samples.empty()) {
    // 평균 가속 크기(진폭)로 g를 추정 (방향은 world의 -Z로 유지)
    double mean_abs = 0.0;
    for (const auto& a : acc_body_samples) mean_abs += a.norm();
    mean_abs /= static_cast<double>(acc_body_samples.size());

    // g 크기를 샘플에 맞춰 약간 보정(너무 튀지 않게 clamp)
    const double g_est = std::isfinite(mean_abs) ? std::max(8.0, std::min(11.0, mean_abs)) : p.g_norm;
    s.grav_w = Eigen::Vector3d(0, 0, -g_est);
  }
  return s;
}

/**
 * @brief 자이로 샘플(정지 상태)을 이용해 초기 자이로 바이어스 추정
 *  - 평균값을 초기 bg로 설정
 */
inline void estimateGyroBias(const std::vector<Eigen::Vector3d>& gyr_body_samples,
                             Eigen::Vector3d& bg_out) {
  if (gyr_body_samples.empty()) { bg_out.setZero(); return; }
  Eigen::Vector3d sum = Eigen::Vector3d::Zero();
  for (const auto& g : gyr_body_samples) sum += g;
  bg_out = sum / static_cast<double>(gyr_body_samples.size());
}

} // namespace state
} // namespace legkilo

#endif // LEG_KILO_STATE_INITIAL_HPP

