// options.cc — ROS2 Humble minimal implementation
// ------------------------------------------------
// 이 파일은 ROS1 의존성을 제거하고, 프로젝트 전역 종료 플래그만 제공한다.
// (leg_kilo_node.cc에서 SIGINT 시 FLAG_EXIT=true; 로 종료를 트리거)
//
// 만약 기존에 options.cc가 YAML/파라미터 파싱을 하던 코드가 있었다면
// 그 부분은 ros_interface(ROS2 rclcpp 기반)로 옮기는 것을 권장한다.

#include "options.h"
#include <atomic>

namespace legkilo {
namespace options {

// 전역 종료 플래그(ROS2에서도 동일하게 사용)
std::atomic_bool FLAG_EXIT{false};

}  // namespace options
}  // namespace legkilo
