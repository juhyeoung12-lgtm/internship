#ifndef LEG_KILO_OPTIONS_H
#define LEG_KILO_OPTIONS_H

#include <atomic>

namespace legkilo {
namespace options {

// 글로벌 종료 플래그
// - leg_kilo_node.cc 의 SIGINT 핸들러와 메인 루프에서 사용
// - ros_interface 등 어디서든 읽을 수 있음
extern std::atomic_bool FLAG_EXIT;

}  // namespace options
}  // namespace legkilo

#endif  // LEG_KILO_OPTIONS_H

