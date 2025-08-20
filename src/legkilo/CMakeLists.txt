cmake_minimum_required(VERSION 3.16)
project(legkilo)

# ===== Build setup =====
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)               # colcon에서 덮어쓸 수 있음
add_definitions(-DROOT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/\")
add_compile_options(-Wall -Wextra -fexceptions -pthread)

# ===== ROS2 / ament =====
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(unitree_legged_msgs REQUIRED)     # ✅ unitree 메시지 의존 추가

# ===== 3rd-party =====
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io filters)
find_package(yaml-cpp REQUIRED)
find_package(glog REQUIRED)          # 타깃: glog::glog
# find_package(TBB REQUIRED)         # 사용 시 활성화 (타깃: TBB::tbb)

# ===== Include dirs =====
include_directories(
  include
  ${EIGEN3_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

# ===== Sources / Headers =====
set(HEADERS
  include/common.hpp
  include/glog_utils.hpp
  include/timer_utils.hpp
  include/yaml_helper.hpp
  include/state_initial.hpp
  include/voxel_map.h
  include/lidar_processing.h
  include/ros_interface.h
  include/options.h
  include/eskf.h
  include/kinematics.h
)

set(SOURCES
  src/lidar_processing.cc
  src/ros_interface.cc
  src/options.cc
  src/eskf.cc
  src/voxel_map.cc
  src/kinematics.cc
)

# ===== Library =====
add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})
ament_target_dependencies(${PROJECT_NAME}
  rclcpp tf2_ros sensor_msgs nav_msgs geometry_msgs pcl_conversions
  unitree_legged_msgs                                # ✅ 링크/인클루드 경로 자동 연결
)
target_link_libraries(${PROJECT_NAME}
  ${PCL_LIBRARIES}
  yaml-cpp
  glog::glog
  # TBB::tbb
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
add_definitions(${PCL_DEFINITIONS})

# ===== Executable node =====
# 현재 실행 파일명은 'legkilo_node' (런치의 executable도 동일하게 맞추기)
add_executable(${PROJECT_NAME}_node src/leg_kilo_node.cc)
target_link_libraries(${PROJECT_NAME}_node ${PROJECT_NAME})
ament_target_dependencies(${PROJECT_NAME}_node
  rclcpp tf2_ros sensor_msgs nav_msgs geometry_msgs pcl_conversions
  unitree_legged_msgs
)

# ===== Install =====
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

# 런치/리소스 설치(디렉토리가 있을 때)
install(DIRECTORY launch rviz config
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL)

ament_package()


