#ifndef LEG_KILO_VOXEL_GRID_HPP
#define LEG_KILO_VOXEL_GRID_HPP

#include <memory>
#include <limits>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

#include "common.hpp"  // common::PointCloudType = pcl::PointCloud<pcl::PointXYZINormal>

namespace legkilo {
namespace filters {

/**
 * @brief PCL VoxelGrid 얇은 래퍼 (ROS 비의존)
 */
template <typename PointT = pcl::PointXYZINormal>
class VoxelGrid {
public:
  using Cloud      = pcl::PointCloud<PointT>;
  using CloudPtr   = typename Cloud::Ptr;
  using CloudConst = typename Cloud::ConstPtr;

  VoxelGrid() { voxel_.setDownsampleAllData(true); }

  void setLeafSize(double lx, double ly, double lz) {
    voxel_.setLeafSize(static_cast<float>(std::max(0.0, lx)),
                       static_cast<float>(std::max(0.0, ly)),
                       static_cast<float>(std::max(0.0, lz)));
  }

  void setLeafSize(double l) { setLeafSize(l, l, l); }

  void setInputCloud(const CloudConst& cloud) { voxel_.setInputCloud(cloud); }

  void filter(Cloud& output) { voxel_.filter(output); }

  void filter(CloudPtr& output) {
    if (!output) output.reset(new Cloud());
    voxel_.filter(*output);
  }

private:
  pcl::VoxelGrid<PointT> voxel_;
};

template <typename PointT = pcl::PointXYZINormal>
inline typename pcl::PointCloud<PointT>::Ptr
applyVoxelGrid(const typename pcl::PointCloud<PointT>::ConstPtr& in, double leaf) {
  using Cloud   = pcl::PointCloud<PointT>;
  using CloudPt = typename Cloud::Ptr;
  if (!in || in->empty() || leaf <= 0.0) {
    CloudPt out(new Cloud());
    if (in) *out = *in;
    return out;
  }
  VoxelGrid<PointT> vg;
  vg.setLeafSize(leaf);
  vg.setInputCloud(in);
  CloudPt out(new Cloud());
  vg.filter(out);
  return out;
}

} // namespace filters
} // namespace legkilo

#endif // LEG_KILO_VOXEL_GRID_HPP

