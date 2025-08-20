#ifndef LEG_KILO_LIDAR_PROCESSING_H
#define LEG_KILO_LIDAR_PROCESSING_H

// 프로젝트 공용 타입 정의 (PointCloudType, LidarScan 등)
#include "common.hpp"

// ROS2
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

namespace legkilo {

/**
 * @brief LiDAR 포인트클라우드 전처리 (ROS2)
 *  - Ouster 등에서 들어오는 PointCloud2를 파싱
 *  - (선택) 모듈러/voxel 기반 다운샘플
 *  - 각 포인트의 스캔 내 상대시간을 p.curvature에 기록
 *  - 결과는 common::LidarScan으로 반환
 */
class LidarProcessing {
public:
  struct Config {
    int    filter_num_       = 1;     ///< 모듈러 샘플링 (i % filter_num_ == 0만 사용)
    float  time_scale_       = 1.0f;  ///< per-point 't' 단위 스케일 (예: ns→s: 1e-9)
    double voxel_leaf_size_  = 0.0;   ///< >0이면 VoxelGrid 다운샘플
    double min_range_        = 0.0;   ///< 근거리 컷
    double max_range_        = 0.0;   ///< <=0이면 무제한, >0이면 원거리 컷
  };

  explicit LidarProcessing(const Config& cfg);

  /**
   * @brief Ouster PointCloud2 처리
   * @param msg        입력 ROS2 포인트클라우드
   * @param lidar_scan 출력: 다운샘플된 포인트와 (begin/end) 시간
   *
   * 구현 상세(동일 cc 파일 기준):
   *  - 필드 존재 시 intensity 사용
   *  - 필드 't'가 있으면 time_scale_을 적용한 뒤 첫 점 기준 상대시간을 p.curvature에 저장
   *  - voxel_leaf_size_ > 0이면 VoxelGrid 적용
   */
  void ousterHandler(const sensor_msgs::msg::PointCloud2::ConstSharedPtr& msg,
                     common::LidarScan& lidar_scan);

private:
  // 범위 기반 블라인드 체크
  bool blindCheck(float x, float y, float z) const;

private:
  Config config_;
};

} // namespace legkilo

#endif // LEG_KILO_LIDAR_PROCESSING_H

