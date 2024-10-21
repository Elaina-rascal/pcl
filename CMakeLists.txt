cmake_minimum_required(VERSION 3.6)
project(MY_GRAND_PROJECT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(PCL 1.3 REQUIRED)
find_package(fmt REQUIRED)

# 创建一个接口库
# add_library(pcl_common INTERFACE)

# # 设置接口库的包含目录、链接库和编译定义
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# target_include_directories(pcl_common INTERFACE ${PCL_INCLUDE_DIRS})
# target_link_libraries(pcl_common INTERFACE ${PCL_LIBRARIES})
# target_compile_definitions(pcl_common INTERFACE ${PCL_DEFINITIONS})
# 创建可执行文件
add_executable(pclloader loadtest.cpp)
add_executable(pcd_write_test test.cpp)
add_executable(viewer_test viewtest.cpp)
target_link_libraries(viewer_test ${PCL_LIBRARIES} fmt::fmt)
target_link_libraries(pclloader ${PCL_LIBRARIES} fmt::fmt)
target_link_libraries(pcd_write_test ${PCL_LIBRARIES})