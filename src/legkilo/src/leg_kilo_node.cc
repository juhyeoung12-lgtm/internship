// ROS2 Humble version of leg_kilo_node.cc
// -----------------------------------------------------------
// 빌드 가정:
//  - class legkilo::RosInterface : public rclcpp::Node  (ros_interface.{hpp,cc})
//  - legkilo::options::FLAG_EXIT  (options.{h,cc})      ← 종료 플래그
//  - legkilo::Timer::logAllAverTime()                   ← 선택적 성능 로거
//  - glog_utils.hpp                                     ← 기존 로깅 래퍼 (선택)
// -----------------------------------------------------------

#include <csignal>
#include <chrono>
#include <memory>
#include <exception>

#include <rclcpp/rclcpp.hpp>

// 네 프로젝트 헤더 경로에 맞게 조정
#include "ros_interface.h"       // RosInterface (ROS2로 포팅된 것)
#include "options.h"               // legkilo::options::FLAG_EXIT
#include "glog_utils.hpp"          // 선택: 기존 glog 래퍼
#include "timer_utils.hpp"         // 선택: Timer::logAllAverTime()

namespace {

void sigHandle(int sig) {
  // Ctrl+C 등 신호 처리
  legkilo::options::FLAG_EXIT = true;
  // glog 사용(선택). glog 미사용이면 std::fprintf 등으로 대체 가능
  LOG(INFO) << "catch sig " << sig << "  FLAG_EXIT = True";
  // ROS2 종료
  rclcpp::shutdown();
}

} // namespace

int main(int argc, char** argv) {
  // ----- (선택) 기존 glog 초기화 -----
  // 로그 디렉토리는 프로젝트에 맞게 조정
  std::unique_ptr<legkilo::Logging> logging;
  try {
    logging.reset(new legkilo::Logging(argc, argv, "logs"));
  } catch (...) {
    // glog 초기화 실패해도 실행 계속
  }

  // ----- ROS2 초기화 -----
  rclcpp::init(argc, argv);
  std::signal(SIGINT, sigHandle);

  try {
    // RosInterface는 rclcpp::Node 상속을 가정
    auto node = std::make_shared<legkilo::RosInterface>(rclcpp::NodeOptions{});

    // gflags 대체: ROS2 파라미터 사용
    // launch에서 parameters=[{'config_file': 'config/leg_fusion.yaml'}]로 주입 가능
    const std::string default_cfg = "config/leg_fusion.yaml";
    if (!node->has_parameter("config_file")) {
      node->declare_parameter<std::string>("config_file", default_cfg);
    }
    std::string config_file = node->get_parameter("config_file").as_string();

    // 기존 초기화 루틴 호출(내부는 ROS2 API로 포팅되어 있어야 함)
    node->rosInit(config_file);

    LOG(INFO) << "Leg KILO Node Starts";

    // Executor 구성
    rclcpp::executors::SingleThreadedExecutor exec;
    exec.add_node(node);

    // 5 kHz 주기 (200 μs)
    rclcpp::Rate rate(std::chrono::microseconds(200));

    // 메인 루프
    while (rclcpp::ok() && !legkilo::options::FLAG_EXIT) {
      // 사용자 주기 처리 (센서 fusion/맵 update 등)
      node->run();

      // 콜백 처리
      exec.spin_some();

      // 주기 대기
      rate.sleep();
    }

    LOG(INFO) << "Leg KILO Node Ends";

    // (선택) 평균 시간 로그 출력
    try {
      legkilo::Timer::logAllAverTime();
    } catch (...) {
      // 무시
    }

    if (logging) logging->flushLogFiles();

  } catch (const std::exception& e) {
    // 치명 오류 시 로그 남기고 종료
    RCLCPP_FATAL(rclcpp::get_logger("leg_kilo_node"),
                 "Unhandled exception: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(rclcpp::get_logger("leg_kilo_node"),
                 "Unhandled unknown exception");
  }

  rclcpp::shutdown();
  return 0;
}

