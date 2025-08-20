#ifndef LEGKILO_VOXEL_MAP_H
#define LEGKILO_VOXEL_MAP_H

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <cstdint>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "common.hpp"  // common::PointCloudType 정의

namespace legkilo {

class VoxelMap {
public:
  // ===== 공개 키/해시 =====
  struct VoxelKey {
    int32_t ix{0}, iy{0}, iz{0};
    bool operator==(const VoxelKey& o) const noexcept {
      return ix == o.ix && iy == o.iy && iz == o.iz;
    }
  };

  struct VoxelKeyHash {
    std::size_t operator()(const VoxelKey& k) const noexcept {
      uint64_t h = static_cast<uint64_t>(k.ix) * 73856093ull
                 ^ static_cast<uint64_t>(k.iy) * 19349663ull
                 ^ static_cast<uint64_t>(k.iz) * 83492791ull;
      return static_cast<std::size_t>(h);
    }
  };

  // 좌표 -> 보xel 키 (정적 멤버)
  static VoxelKey pointToKey(const Eigen::Vector3d& p, double voxel_size);

  // ===== 설정 =====
  struct Config {
    double voxel_size{0.1};            // 보xel 한 변 [m]
    double max_update_range{10.0};     // 반경 [m]
    bool   use_centroid{true};         // centroid 사용 여부
    int    max_points_per_voxel{50};   // 원 포인트 저장시 최대 개수
  };

  // ===== 생성자 =====
  VoxelMap();                       // 기본값 사용
  explicit VoxelMap(const Config& cfg); // 사용자 설정

  // ===== API =====
  void insert(const common::PointCloudType::ConstPtr& cloud_body,
              const Eigen::Isometry3d& T_wb);

  void extractLocal(const Eigen::Vector3d& center_w, double radius,
                    pcl::PointCloud<pcl::PointXYZINormal>::Ptr out) const;

  const Config& config() const { return cfg_; }
  void setConfig(const Config& c) { cfg_ = c; }

  std::size_t voxelCount() const {
    std::lock_guard<std::mutex> lk(mtx_);
    return voxels_.size();
  }

private:
  struct VoxelData {
    // centroid 사용 시
    double sum_x{0.0}, sum_y{0.0}, sum_z{0.0}, sum_i{0.0};
    int    count{0};
    // 원 포인트 저장 시
    std::vector<pcl::PointXYZINormal> pts;
  };

  Config cfg_;
  mutable std::mutex mtx_;
  std::unordered_map<VoxelKey, VoxelData, VoxelKeyHash> voxels_;
};

} // namespace legkilo

#endif // LEGKILO_VOXEL_MAP_H


