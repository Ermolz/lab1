#include <iostream>
#include "Point.h"

Point::Point(double x_val, double y_val)
    : x(x_val), y(y_val) {
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
