cmake_minimum_required(VERSION 3.16)
project(unitree_legged_msgs)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 메시지에서 참조하는 의존 인터페이스
find_package(builtin_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

# ROS1 파일 리스트를 그대로 반영
set(msg_files
  "msg/MotorCmd.msg"
  "msg/MotorState.msg"
  "msg/BmsCmd.msg"
  "msg/BmsState.msg"
  "msg/Cartesian.msg"
  "msg/IMU.msg"
  "msg/LED.msg"
  "msg/LowCmd.msg"
  "msg/LowState.msg"
  "msg/HighCmd.msg"
  "msg/HighState.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES builtin_interfaces std_msgs geometry_msgs sensor_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()

