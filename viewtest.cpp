#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
// 包含相关头文件
#include "filesystem"
#include <pcl/visualization/pcl_visualizer.h>
typedef pcl::PointXYZ PointT;

int main()
{
    auto pcd1path = static_cast<std::string>(std::filesystem::path(__FILE__).parent_path()) + "/data/tutorials/ism_test_cat.pcd";
    auto pcd2path = static_cast<std::string>(std::filesystem::path(__FILE__).parent_path()) + "/data/tutorials/ism_test_horse.pcd";
    // 读取点云
    pcl::PointCloud<PointT>::Ptr cloud1(new pcl::PointCloud<PointT>);
    pcl::io::loadPCDFile(pcd1path, *cloud1);

    pcl::PointCloud<PointT>::Ptr cloud2(new pcl::PointCloud<PointT>);
    pcl::io::loadPCDFile(pcd2path, *cloud2);

    // 定义对象
    pcl::visualization::PCLVisualizer viewer;
    // 设置背景颜色，默认黑色
    viewer.setBackgroundColor(100, 100, 100); // rgb

    // --- 显示点云数据 ----
    // "cloud1" 为显示id，默认cloud,显示多个点云时用默认会报警告。
    viewer.addPointCloud(cloud1, "cloud1");

    pcl::visualization::PointCloudColorHandlerCustom<PointT> red(cloud2, 255, 0, 0); // rgb
    // 将点云设置颜色，默认白色
    viewer.addPointCloud(cloud2, red, "cloud2");

    // 将两个点连线
    PointT temp1 = cloud1->points[0];
    PointT temp2 = cloud1->points[1];
    viewer.addLine(temp1, temp2, "line0");
    // 同样可以设置线的颜色，
    // viewer.addLine(temp1, temp2, 255，0，0， "line0");

    // --- 显示网格数据 ---
    pcl::PolygonMesh mesh;
    pcl::io::loadPLYFile("read.ply", mesh);

    viewer.addPolygonMesh(mesh);

    // 开始显示2种方法,任选其一
    // 1. 阻塞式
    viewer.spin();

    // 2. 非阻塞式
    // while (!viewer.wasStopped())
    // {
    //     viewer.spinOnce(100);
    //     boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    //     // 可添加其他操作
    // }

    system("pause");
    return 0;
}