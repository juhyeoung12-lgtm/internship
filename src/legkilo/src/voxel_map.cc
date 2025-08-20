#include "voxel_map.h"

#include <cmath>
#include <limits>
#include <utility>

namespace legkilo {

// ===== 생성자 정의 =====
VoxelMap::VoxelMap() : cfg_{} {}
VoxelMap::VoxelMap(const Config& cfg) : cfg_(cfg) {}

// ===== 정적 멤버: 좌표 -> 보xel 키 =====
VoxelMap::VoxelKey VoxelMap::pointToKey(const Eigen::Vector3d& p, double vs) {
  return VoxelMap::VoxelKey{
    static_cast<int32_t>(std::floor(p.x() / vs)),
    static_cast<int32_t>(std::floor(p.y() / vs)),
    static_cast<int32_t>(std::floor(p.z() / vs))
  };
}

void VoxelMap::insert(const common::PointCloudType::ConstPtr& cloud_body,
                      const Eigen::Isometry3d& T_wb)
{
  if (!cloud_body || cloud_body->empty()) return;

  const double vs = cfg_.voxel_size;
  const double max_r2 = cfg_.max_update_range * cfg_.max_update_range;

  std::lock_guard<std::mutex> lk(mtx_);

  for (const auto& pb : cloud_body->points) {
    // body -> world
    Eigen::Vector3d p_b(pb.x, pb.y, pb.z);
    Eigen::Vector3d p_w = T_wb * p_b;

    if (p_w.squaredNorm() > max_r2) continue;

    auto key = pointToKey(p_w, vs);
    auto& vox = voxels_[key];

    if (cfg_.use_centroid) {
      vox.sum_x += p_w.x();
      vox.sum_y += p_w.y();
      vox.sum_z += p_w.z();
      vox.sum_i += pb.intensity;
      if (vox.count < cfg_.max_points_per_voxel) ++vox.count;
    } else {
      if (static_cast<int>(vox.pts.size()) < cfg_.max_points_per_voxel) {
        pcl::PointXYZINormal pw;
        pw.x = static_cast<float>(p_w.x());
        pw.y = static_cast<float>(p_w.y());
        pw.z = static_cast<float>(p_w.z());
        pw.intensity = pb.intensity;
        pw.normal_x = pw.normal_y = pw.normal_z = 0.f;
        pw.curvature = 0.f;
        vox.pts.emplace_back(std::move(pw));
      }
    }
  }
}

void VoxelMap::extractLocal(const Eigen::Vector3d& center_w, double radius,
                            pcl::PointCloud<pcl::PointXYZINormal>::Ptr out) const
{
  if (!out) return;
  out->clear();

  std::lock_guard<std::mutex> lk(mtx_);
  if (voxels_.empty()) {
    out->width = 0;
    out->height = 1;
    out->is_dense = false;
    return;
  }

  const double vs = cfg_.voxel_size;
  const double r = (radius > 0.0) ? radius : cfg_.max_update_range;
  const double r2 = r * r;

  const int rx = static_cast<int>(std::ceil(r / vs));
  auto kc = pointToKey(center_w, vs);

  out->points.reserve(out->points.size() + 50000);

  for (int dx = -rx; dx <= rx; ++dx) {
    for (int dy = -rx; dy <= rx; ++dy) {
      for (int dz = -rx; dz <= rx; ++dz) {
        VoxelKey k{ kc.ix + dx, kc.iy + dy, kc.iz + dz };

        auto it = voxels_.find(k);
        if (it == voxels_.end()) continue;

        const auto& vox = it->second;

        if (cfg_.use_centroid) {
          if (vox.count == 0) continue;

          Eigen::Vector3d c(vox.sum_x, vox.sum_y, vox.sum_z);
          c /= static_cast<double>(vox.count);

          if ((c - center_w).squaredNorm() > r2) continue;

          pcl::PointXYZINormal p;
          p.x = static_cast<float>(c.x());
          p.y = static_cast<float>(c.y());
          p.z = static_cast<float>(c.z());
          p.intensity = static_cast<float>(vox.sum_i / std::max(1, vox.count));
          p.normal_x = p.normal_y = p.normal_z = 0.f;
          p.curvature = 0.f;

          out->points.emplace_back(std::move(p));
        } else {
          for (const auto& p : vox.pts) {
            Eigen::Vector3d pw(p.x, p.y, p.z);
            if ((pw - center_w).squaredNorm() <= r2) {
              out->points.emplace_back(p);
            }
          }
        }
      }
    }
  }

  out->width = static_cast<uint32_t>(out->points.size());
  out->height = 1;
  out->is_dense = false;
}

} // namespace legkilo

