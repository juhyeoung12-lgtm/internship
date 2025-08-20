#include "kinematics.h"

// ROS2: rclcpp와 Unitree 메시지 헤더
#include <rclcpp/rclcpp.hpp>
#include <unitree_legged_msgs/msg/high_state.hpp>

namespace legkilo {

// ROS2 버전: unitree_legged_msgs::msg::HighState 사용
void Kinematics::processing(const unitree_legged_msgs::msg::HighState& high_state,
                            common::KinImuMeas& kin_imu_meas) {
    // ROS1: high_state.stamp.toSec()
    // ROS2: rclcpp::Time(high_state.stamp).seconds()
    kin_imu_meas.time_stamp_ = rclcpp::Time(high_state.stamp).seconds();

    // IMU 복사
    for (int i = 0; i < 3; ++i) {
        kin_imu_meas.acc_[i] = high_state.imu.accelerometer[i];
        kin_imu_meas.gyr_[i] = high_state.imu.gyroscope[i];
    }

    /*  4 legs, 3 motors
        this project leg order: FR FL RR RL
        unitree leg order:      FL FR RL RR
    */

    // 발 접촉/발힘이 HighState 안에 있다면 (필드 이름은 사용 중인 unitree 메시지 버전에 따라 다를 수 있음)
    // - 보통 foot_force나 footForce, contact 같은 배열 이름을 씀
    // - 아래는 기존 코드와 동일하다고 가정하고 그대로 유지
    //   (필드명이 다르면 해당 부분만 네 메시지 정의에 맞게 바꿔줘)

    // 모터 각도/각속도 가져오기 (unitree motorState[q, dq] 사용)
    // FR, FL, RR, RL 순서로 재배열 (원본: FL FR RL RR)
    double foot_angle[4][3] = {{0}};
    double foot_angle_vel[4][3] = {{0}};

    // unitree index → project index 매핑
    //    unitree: [FL(0..2), FR(3..5), RL(6..8), RR(9..11)]
    //    project: [FR(0),   FL(1),    RR(2),    RL(3)]
    // -> FR <- unitree FR(3..5)
    for (int i = 0; i < 3; ++i) {
        foot_angle[0][i]     = high_state.motor_state[3 + i].q;
        foot_angle_vel[0][i] = high_state.motor_state[3 + i].dq;
    }
    // -> FL <- unitree FL(0..2)
    for (int i = 0; i < 3; ++i) {
        foot_angle[1][i]     = high_state.motor_state[0 + i].q;
        foot_angle_vel[1][i] = high_state.motor_state[0 + i].dq;
    }
    // -> RR <- unitree RR(9..11)
    for (int i = 0; i < 3; ++i) {
        foot_angle[2][i]     = high_state.motor_state[9 + i].q;
        foot_angle_vel[2][i] = high_state.motor_state[9 + i].dq;
    }
    // -> RL <- unitree RL(6..8)
    for (int i = 0; i < 3; ++i) {
        foot_angle[3][i]     = high_state.motor_state[6 + i].q;
        foot_angle_vel[3][i] = high_state.motor_state[6 + i].dq;
    }

    // 발 위치/속도 계산 (네가 가진 기존 함수 그대로 사용)
    this->caculateFootPosVel(foot_angle, foot_angle_vel,
                             kin_imu_meas.foot_pos_, kin_imu_meas.foot_vel_);

    // (아래 주석은 원본 디버그 출력 그대로 보존)
    // static int counts = 0;
    // int index = 1;
    // int uni_index = 0;
    // if(!(counts++  % 50)){
    //     std::cout <<  "contact: " << kin_imu_meas.contact_[index] << std::endl;
    //     std::cout << "force: " << high_state.footForce[uni_index] << std::endl;
    //     std::cout << "my pos: " << kin_imu_meas.foot_pos_[index][0] << " "
    //               << kin_imu_meas.foot_pos_[index][1] << " "
    //               << kin_imu_meas.foot_pos_[index][2] << std::endl;
    //     std::cout << "uni pos: " << ...
    // }
}

// ====== 아래는 네 기존 역기구학/야코비안 계산부를 그대로 유지 ======
// 주의: 아래 내용은 원본 코드 그대로이며, ROS API와 무관합니다.
//       (lf_, lt_, lc_, d_ 등 링크 길이/오프셋 상수는 class 멤버로 유지)

void Kinematics::caculateFootPosVel(double foot_angle[4][3],
                                    double foot_angle_vel[4][3],
                                    double foot_pos[4][3],
                                    double foot_vel[4][3]) {
    for (int i = 0; i < 4; ++i) {
        double s1 = sin(foot_angle[i][0]), c1 = cos(foot_angle[i][0]);
        double s2 = sin(foot_angle[i][1]), c2 = cos(foot_angle[i][1]);
        double s3 = sin(foot_angle[i][2]), c3 = cos(foot_angle[i][2]);
        double s23 = sin(foot_angle[i][1] + foot_angle[i][2]);
        double c23 = cos(foot_angle[i][1] + foot_angle[i][2]);

        // 발끝 오프셋 (필요시 네 값으로 교체)
        double lfoot = lfoot_;
        double d = d_;

        // 포지션
        foot_pos[i][0] = -lt_ * s2 + lc_ * c23;
        foot_pos[i][1] = -lfoot * d * s1 - lt_ * c2 * c1 - lc_ * c1 * s23;
        foot_pos[i][2] =  lfoot * d * c1 - lt_ * c2 * s1 - lc_ * s1 * s23;

        // 야코비안 (기존과 동일)
        double jacb[3][3] = {0};

        jacb[0][0] = 0.0;
        jacb[0][1] = -lt_ * c2 - lc_ * s23;
        jacb[0][2] = -lc_ * s23;

        jacb[1][0] = -lfoot * d * c1 + lt_ * c2 * s1 + lc_ * s1 * s23;
        jacb[1][1] = -c1 * (lc_ * s23 + lt_ * s2);
        jacb[1][2] = -lc_ * s23 * s1;

        jacb[2][0] =  lt_ * c2 * c1 + lfoot * d * s1 + lc_ * c1 * s23;
        jacb[2][1] =  c1 * (lc_ * s23 + lt_ * s2);
        jacb[2][2] =  lc_ * s23 * c1;

        // 속도
        foot_vel[i][0] = jacb[0][1] * foot_angle_vel[i][1] + jacb[0][2] * foot_angle_vel[i][2];
        foot_vel[i][1] = jacb[1][0] * foot_angle_vel[i][0] + jacb[1][1] * foot_angle_vel[i][1] + jacb[1][2] * foot_angle_vel[i][2];
        foot_vel[i][2] = jacb[2][0] * foot_angle_vel[i][0] + jacb[2][1] * foot_angle_vel[i][1] + jacb[2][2] * foot_angle_vel[i][2];
    }
}

}  // namespace legkilo

