#ifndef LEG_KILO_KINEMATICS_H
#define LEG_KILO_KINEMATICS_H

// 프로젝트 공용 타입(포인트클라우드, 측정 구조 등)
//  - common::KinImuMeas { time_stamp_, acc_[3], gyr_[3], foot_pos_[4][3], foot_vel_[4][3], contact_[4](선택) }
#include "common.hpp"

// ROS2
#include <rclcpp/rclcpp.hpp>
#include <unitree_legged_msgs/msg/high_state.hpp>

// STL
#include <cstddef>

namespace legkilo {

/**
 * @brief Leg kinematics utility (ROS2)
 *  - 이 헤더는 ROS2용 kinematics.cc와 정확히 매칭됩니다.
 *  - 입력: unitree_legged_msgs::msg::HighState
 *  - 출력: common::KinImuMeas (IMU + 발끝 위치/속도)
 *
 * 링크/오프셋 파라미터:
 *   lc_    : calf(하퇴) 링크 길이
 *   lt_    : thigh(대퇴) 링크 길이
 *   lfoot_ : 발끝 오프셋 길이
 *   d_     : 좌/우 방향 오프셋 계수(기존 코드 그대로 유지)
 */
class Kinematics {
public:
  Kinematics(double lc, double lt, double lfoot, double d)
  : lc_(lc), lt_(lt), lfoot_(lfoot), d_(d) {}

  /**
   * @brief Unitree HighState → Kin/IMU 측정으로 변환
   * @param high_state  Unitree 고빈도 상태 메시지 (ROS2)
   * @param kin_imu_meas 출력 구조 (시간/IMU/발끝 pos, vel)
   *
   * - 시간: kin_imu_meas.time_stamp_ = rclcpp::Time(high_state.stamp).seconds();
   * - 모터 순서 매핑:
   *     unitree: FL(0..2), FR(3..5), RL(6..8), RR(9..11)
   *     project: FR(0),    FL(1),    RR(2),    RL(3)
   */
  void processing(const unitree_legged_msgs::msg::HighState& high_state,
                  common::KinImuMeas& kin_imu_meas);

private:
  /**
   * @brief 발끝 위치/속도 계산 (야코비안 기반)
   * @param foot_angle     [4][3] 각 다리 조인트 각(q)
   * @param foot_angle_vel [4][3] 각 다리 조인트 각속도(dq)
   * @param foot_pos       [4][3] 결과: 발끝 위치
   * @param foot_vel       [4][3] 결과: 발끝 속도
   *
   * 내부에서 다음 멤버(lc_, lt_, lfoot_, d_)를 사용합니다.
   */
  void caculateFootPosVel(double foot_angle[4][3],
                          double foot_angle_vel[4][3],
                          double foot_pos[4][3],
                          double foot_vel[4][3]);

private:
  double lc_{0.0};
  double lt_{0.0};
  double lfoot_{0.0};
  double d_{0.0};
};

} // namespace legkilo

#endif // LEG_KILO_KINEMATICS_H

