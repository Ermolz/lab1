#ifndef POINT_H
#define POINT_H

class Point {
public:
    double x, y;
    Point(double x_val = 0.0, double y_val = 0.0);
    void print() const;
};

#endif // POINT_H
