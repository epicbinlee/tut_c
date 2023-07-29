cmake_minimum_required(VERSION 3.26)
project(tut_c)
set(CMAKE_CXX_STANDARD 17)

# 设置 Boost 安装路径
set(BOOST_ROOT "/usr/local/Cellar/boost/1.82.0_1/")
# 查找 Boost 库
find_package(Boost REQUIRED)
# 添加 Boost 头文件路径
#include_directories("/usr/local/Cellar/boost/1.82.0_1/include/")
include_directories(${Boost_INCLUDE_DIRS})


# 构建可执行文件
add_executable(tut_c
        # print_struct.cpp
        tut_boost.cpp
)

# 链接 Boost 库
target_link_libraries(tut_c PRIVATE Boost::boost)