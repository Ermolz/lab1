#include <iostream>
#include "Point.h"
#include "Triangle.h"

int main() {
    Point A(0, 0);
    Point B(4, 0);
    Point C(2, 3);

    Triangle t(A, B, C);

    std::cout << "Sides of the triangle:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        Triangle::Segment side = t.getSide(i);
        side.print();
    }

    std::cout << "Medians of the triangle:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        Triangle::Segment median = t.getMedian(i);
        std::cout << "Median from vertex " << i << ": ";
        median.print();
    }

    return 0;
}
