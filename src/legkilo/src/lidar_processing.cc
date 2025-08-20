#include "lidar_processing.h"

// ROS2
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>

// PCL
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>

// STL
#include <cmath>
#include <limits>
#include <string>
#include <vector>

namespace legkilo {

namespace {
// 안전한 최소값 클램프
inline double clamp_pos(double v, double minv) { return (v < minv) ? minv : v; }

// PointField 헬퍼
inline bool hasField(const sensor_msgs::msg::PointCloud2& msg, const std::string& name) {
  for (const auto& f : msg.fields) if (f.name == name) return true;
  return false;
}

} // namespace

LidarProcessing::LidarProcessing(const Config& cfg)
: config_(cfg)
{
  // 파라미터 클램프
  config_.time_scale_     = (std::isfinite(config_.time_scale_) ? config_.time_scale_ : 1.0f);
  config_.voxel_leaf_size_ = clamp_pos(config_.voxel_leaf_size_, 0.0);
  config_.min_range_      = clamp_pos(config_.min_range_, 0.0);
  config_.max_range_      = (config_.max_range_ <= 0.0 ? std::numeric_limits<double>::infinity()
                                                       : config_.max_range_);
  if (config_.filter_num_ <= 0) config_.filter_num_ = 1;
}

bool LidarProcessing::blindCheck(float x, float y, float z) const {
  // 기본: 범위 필터만 적용 (필요하면 시야각/블라인드존 추가)
  const double r = std::sqrt(double(x)*x + double(y)*y + double(z)*z);
  if (r < config_.min_range_) return true;
  if (r > config_.max_range_) return true;
  return false;
}

void LidarProcessing::ousterHandler(const sensor_msgs::msg::PointCloud2::ConstSharedPtr& msg,
                                    common::LidarScan& lidar_scan)
{
  using PointT = pcl::PointXYZINormal;

  // 출력 포인트클라우드 준비
  lidar_scan.cloud_.reset(new common::PointCloudType());
  auto& cloud_out = *lidar_scan.cloud_;

  // 필수 필드 체크
  const bool has_x = hasField(*msg, "x");
  const bool has_y = hasField(*msg, "y");
  const bool has_z = hasField(*msg, "z");
  if (!(has_x && has_y && has_z)) {
    RCLCPP_WARN(rclcpp::get_logger("LidarProcessing"),
                "PointCloud2 missing x/y/z fields — skipping frame.");
    return;
  }

  // 선택 필드 (intensity, t)
  const bool has_intensity = hasField(*msg, "intensity");
  const bool has_t         = hasField(*msg, "t"); // Ouster timestamp per-point

  // 포인트 개수
  const int pts_n = msg->width * msg->height;
  cloud_out.points.reserve(pts_n);

  // 스캔 시작/끝 시간 준비
  // per-point 't'가 있으면 이를 이용, 없으면 메시지 스탬프만 사용
  double begin_time = rclcpp::Time(msg->header.stamp).seconds();
  double end_time   = begin_time;

  // per-point t의 첫/끝 추출 (존재할 때)
  double first_point_t = 0.0;
  double last_point_t  = 0.0;
  bool   t_initialized = false;

  if (has_t) {
    // t는 보통 uint32 또는 uint64, 단위는 ns 혹은 us. 여기서는 float/int 두 경우 모두 iterator로 처리.
    // ROS2 iterator는 타입 고정이라, 일반 접근으로 한 번 순회하며 가장 첫/끝 t를 잡자.
    // (PointCloud2는 row-major이므로 front/back 순회로 근사)
    // front
    {
      sensor_msgs::PointCloud2ConstIterator<uint32_t> it_t_u32(*msg, "t");
      sensor_msgs::PointCloud2ConstIterator<uint64_t> it_t_u64(*msg, "t");
      if (it_t_u32 != it_t_u32.end()) {
        first_point_t = static_cast<double>(*it_t_u32);
        t_initialized = true;
      } else if (it_t_u64 != it_t_u64.end()) {
        first_point_t = static_cast<double>(*it_t_u64);
        t_initialized = true;
      } else {
        // 만약 위 타입이 아니면 float 시도
        sensor_msgs::PointCloud2ConstIterator<float> it_t_f(*msg, "t");
        if (it_t_f != it_t_f.end()) {
          first_point_t = static_cast<double>(*it_t_f);
          t_initialized = true;
        }
      }
    }
    // back (마지막 포인트 t를 얻기 위해 전체 순회는 부담이므로, 단순 순회로 마지막만 갱신)
    if (t_initialized) {
      // u32 시도
      bool got = false;
      try {
        for (sensor_msgs::PointCloud2ConstIterator<uint32_t> it(*msg, "t"); it != it.end(); ++it)
          last_point_t = static_cast<double>(*it), got = true;
      } catch (...) {}
      if (!got) {
        try {
          for (sensor_msgs::PointCloud2ConstIterator<uint64_t> it(*msg, "t"); it != it.end(); ++it)
            last_point_t = static_cast<double>(*it), got = true;
        } catch (...) {}
      }
      if (!got) {
        try {
          for (sensor_msgs::PointCloud2ConstIterator<float> it(*msg, "t"); it != it.end(); ++it)
            last_point_t = static_cast<double>(*it), got = true;
        } catch (...) {}
      }

      // 스케일 적용 (ns → s 등)
      first_point_t *= static_cast<double>(config_.time_scale_);
      last_point_t  *= static_cast<double>(config_.time_scale_);

      lidar_scan.lidar_begin_time_ = begin_time + first_point_t;
      lidar_scan.lidar_end_time_   = begin_time + last_point_t;
    } else {
      // 필드가 있으나 타입 파악 실패 → 메시지 스탬프만 사용
      lidar_scan.lidar_begin_time_ = begin_time;
      lidar_scan.lidar_end_time_   = end_time;
    }
  } else {
    // per-point t 없음
    lidar_scan.lidar_begin_time_ = begin_time;
    lidar_scan.lidar_end_time_   = end_time;
  }

  // 실제 포인트 파싱
  sensor_msgs::PointCloud2ConstIterator<float> it_x(*msg, "x");
  sensor_msgs::PointCloud2ConstIterator<float> it_y(*msg, "y");
  sensor_msgs::PointCloud2ConstIterator<float> it_z(*msg, "z");

  // intensity (옵션)
  std::unique_ptr<sensor_msgs::PointCloud2ConstIterator<float>> it_intensity;
  if (has_intensity) {
    it_intensity.reset(new sensor_msgs::PointCloud2ConstIterator<float>(*msg, "intensity"));
  }

  // t (옵션): 각 포인트 상대시간 저장 위해 다시 iterator 사용
  // 타입은 우선순위: u32 → u64 → float
  enum class TType { NONE, U32, U64, F32 };
  TType ttype = TType::NONE;

  std::unique_ptr<sensor_msgs::PointCloud2ConstIterator<uint32_t>> it_t_u32;
  std::unique_ptr<sensor_msgs::PointCloud2ConstIterator<uint64_t>> it_t_u64;
  std::unique_ptr<sensor_msgs::PointCloud2ConstIterator<float>>    it_t_f32;

  if (has_t) {
    try { it_t_u32.reset(new sensor_msgs::PointCloud2ConstIterator<uint32_t>(*msg, "t")); ttype = TType::U32; } catch (...) {}
    if (ttype == TType::NONE) { try { it_t_u64.reset(new sensor_msgs::PointCloud2ConstIterator<uint64_t>(*msg, "t")); ttype = TType::U64; } catch (...) {} }
    if (ttype == TType::NONE) { try { it_t_f32.reset(new sensor_msgs::PointCloud2ConstIterator<float>(*msg, "t")); ttype = TType::F32; } catch (...) {} }
  }

  // 모듈러 다운샘플
  int kept = 0;
  for (int i = 0; i < pts_n; ++i, ++it_x, ++it_y, ++it_z) {
    // filter_num_ 로 샘플링
    if ((i % config_.filter_num_) != 0) {
      if (has_intensity) ++(*it_intensity);
      if (ttype == TType::U32) ++(*it_t_u32);
      else if (ttype == TType::U64) ++(*it_t_u64);
      else if (ttype == TType::F32) ++(*it_t_f32);
      continue;
    }

    const float x = *it_x, y = *it_y, z = *it_z;
    if (blindCheck(x, y, z)) {
      if (has_intensity) ++(*it_intensity);
      if (ttype == TType::U32) ++(*it_t_u32);
      else if (ttype == TType::U64) ++(*it_t_u64);
      else if (ttype == TType::F32) ++(*it_t_f32);
      continue;
    }

    PointT p;
    p.x = x;
    p.y = y;
    p.z = z;

    // intensity
    if (has_intensity) {
      p.intensity = **it_intensity;
      ++(*it_intensity);
    } else {
      p.intensity = 0.0f;
    }

    // curvature ← 상대 시간 저장 (첫 포인트 기준)
    if (ttype != TType::NONE && t_initialized) {
      double tval = 0.0;
      if (ttype == TType::U32) { tval = static_cast<double>(**it_t_u32); ++(*it_t_u32); }
      else if (ttype == TType::U64) { tval = static_cast<double>(**it_t_u64); ++(*it_t_u64); }
      else /* F32 */ { tval = static_cast<double>(**it_t_f32); ++(*it_t_f32); }

      tval *= static_cast<double>(config_.time_scale_);
      p.curvature = static_cast<float>(tval - first_point_t); // 상대시간(초) 저장
    } else {
      p.curvature = 0.0f;
      if (ttype == TType::U32) ++(*it_t_u32);
      else if (ttype == TType::U64) ++(*it_t_u64);
      else if (ttype == TType::F32) ++(*it_t_f32);
    }

    // 노멀은 미사용 → 0
    p.normal_x = p.normal_y = p.normal_z = 0.0f;

    cloud_out.points.emplace_back(std::move(p));
    ++kept;
  }

  cloud_out.width  = static_cast<uint32_t>(cloud_out.points.size());
  cloud_out.height = 1;
  cloud_out.is_dense = false;

  // Voxel 다운샘플 (옵션)
  if (config_.voxel_leaf_size_ > 0.0) {
    pcl::VoxelGrid<PointT> voxel;
    voxel.setLeafSize(config_.voxel_leaf_size_,
                      config_.voxel_leaf_size_,
                      config_.voxel_leaf_size_);
    voxel.setInputCloud(lidar_scan.cloud_);
    common::PointCloudType::Ptr filtered(new common::PointCloudType());
    voxel.filter(*filtered);
    lidar_scan.cloud_.swap(filtered);
  }

  // 디버그 로그
  RCLCPP_DEBUG(rclcpp::get_logger("LidarProcessing"),
               "Ouster frame: input=%d, kept=%d, out=%zu, begin=%.6f, end=%.6f",
               pts_n, kept, lidar_scan.cloud_->points.size(),
               lidar_scan.lidar_begin_time_, lidar_scan.lidar_end_time_);
}

} // namespace legkilo

