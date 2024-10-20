/**
 * @file loadtest.cpp
 * @author Elaina (1463967532@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-10-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "pcl/io/pcd_io.h"
#include <filesystem>
#include <memory>
#include <pcl/impl/point_types.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
int main(int argc, char **argv) {
  using namespace std;
  unique_ptr<pcl::PointCloud<pcl::PointXYZ>> cloud_ptr;
  cloud_ptr.reset(new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFile(
          static_cast<string>(filesystem::path(__FILE__).parent_path()) +
              "/data/tutorials/ism_test_cat.pcd",
          *cloud_ptr) == -1) {
    PCL_ERROR("Couldn't read file test_pcd.pcd \n");
    return -1;
  } else {
    cout << "Loaded " << cloud_ptr->width * cloud_ptr->height
         << " data points from test_pcd.pcd with the following fields: "
         << endl;
  }
}