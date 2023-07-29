//
// Created by lee bin on 2023/7/29.
//

#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace bg = boost::geometry;

int main() {
    // 定义点类型（2D点，带有笛卡尔坐标）
    typedef bg::model::d2::point_xy<double> point;

    // 定义两个点
    point p1(1.0, 2.0);
    point p2(4.0, 6.0);

    // 计算两点之间的距离
    double distance = bg::distance(p1, p2);

    std::cout << "两点之间的距离：" << distance << std::endl;

    return 0;
}

