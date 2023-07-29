//
// Created by lee bin on 2023/7/29.
//

#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Arr_segment_traits_2.h>
#include <CGAL/Surface_sweep_2_algorithms.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
typedef CGAL::Arr_segment_traits_2<Kernel> Traits_2;
typedef Traits_2::Curve_2 Segment_2;

namespace bg = boost::geometry;

int main() {
    std::cout << "测试用例：boost求解欧氏距离. --------------------------------------------" << std::endl;

    // 定义点类型（2D点，带有笛卡尔坐标）
    typedef bg::model::d2::point_xy<double> point;

    // 定义两个点
    point p1(1.0, 2.0);
    point p2(4.0, 6.0);

    // 计算两点之间的距离
    double distance = bg::distance(p1, p2);

    std::cout << "两点之间的距离：" << distance << std::endl;

    std::cout << "测试用例：cgal求解交点. --------------------------------------------" << std::endl;

    // Construct the input segments.
    Segment_2 segments[] = {Segment_2(Point_2(1, 5), Point_2(8, 5)),
                            Segment_2(Point_2(1, 1), Point_2(8, 8)),
                            Segment_2(Point_2(3, 1), Point_2(3, 8)),
                            Segment_2(Point_2(8, 5), Point_2(8, 8))};

    // Compute all intersection points.
    std::list<Point_2> pts;
    CGAL::compute_intersection_points(segments, segments + 4, std::back_inserter(pts));

    // Print the result.
    std::cout << "Found " << pts.size() << " intersection points: " << std::endl;
    std::copy(pts.begin(), pts.end(), std::ostream_iterator<Point_2>(std::cout, "\n"));

    // Compute the non-intersecting sub-segments induced by the input segments.
    std::list<Segment_2> sub_segs;
    CGAL::compute_subcurves(segments, segments + 4, std::back_inserter(sub_segs));

    std::cout << "Found " << sub_segs.size() << " interior-disjoint sub-segments." << std::endl;
    assert(CGAL::do_curves_intersect(segments, segments + 4));

    return 0;
}

