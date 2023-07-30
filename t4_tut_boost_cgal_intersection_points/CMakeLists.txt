cmake_minimum_required(VERSION 3.26)
project(tut_c)
set(CMAKE_CXX_STANDARD 17)

# 设置 Boost 安装路径
set(BOOST_ROOT "/usr/local/Cellar/boost/1.82.0_1/")
set(CGAL_DIR "/usr/local/Cellar/cgal/5.6/")

# 查找Boost库并自动设置变量，例如会自动设置如下的变量
# Boost_FOUND: 表示是否找到了 Boost 库。如果找到了，该变量的值为 TRUE，否则为 FALSE。
# Boost_INCLUDE_DIRS: 包含 Boost 头文件的路径。该变量保存了 Boost 库的头文件路径，以便在编译时能够正确包含 Boost 头文件。
# Boost_LIBRARIES: 包含要链接的 Boost 库的名称。该变量保存了链接 Boost 库时需要用到的库的名称。
# Boost_VERSION: 表示找到的 Boost 库的版本号。例如，如果找到的 Boost 版本是 1.76.0，那么该变量的值将是 "1.76.0"。
find_package(Boost REQUIRED)

# 导入cgal,去掉warning
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)
find_package(CGAL REQUIRED COMPONENTS Core)

# 打印变量值
message("${PROJECT_NAME}: Boost--------------------------------------------------")
message(STATUS "测试是否找到Boost变量, 是否找到: ${Boost_FOUND}")
message(STATUS "测试是否找到Boost变量, 头文件目录: ${Boost_INCLUDE_DIRS}")

message("${PROJECT_NAME}: CGAL--------------------------------------------------")
message(STATUS "CGAL的版本号: ${CGAL_USE_FILE}")
message(STATUS "判断是否找到了CGAL库: ${CGAL_FOUND}")
message(STATUS "CGAL头文件: ${CGAL_INCLUDE_DIRS}")

# 添加 Boost 头文件路径
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CGAL_INCLUDE_DIRS})

message("${PROJECT_NAME}: 可执行文件--------------------------------------------------")

# 构建可执行文件
add_executable(tut_c
        # print_struct.cpp
        tut_cgal_compute_intersection_points.cpp
)

# 链接 Boost 库 (CMake 会查找系统中已经安装的 Boost 库，并在链接过程中使用这些库。如果找不到 Boost 库，CMake 将会报错)
target_link_libraries(tut_c PRIVATE Boost::boost)
target_link_libraries(tut_c PRIVATE CGAL::CGAL CGAL::CGAL_Core)