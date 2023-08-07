cmake_minimum_required(VERSION 3.26)
project(tut_c)
set(CMAKE_CXX_STANDARD 17)

find_package(ZLIB REQUIRED)

# 构建可执行文件
add_executable(tut_c win_conan.cpp)

target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)