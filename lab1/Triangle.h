#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include <stdexcept>

class Triangle {
public:
    class Segment {
    public:
        const Point* p1;
        const Point* p2;
        Segment(const Point* pt1, const Point* pt2);
        void print() const;
    };

private:
    Point vertices[3];

public:
    Triangle(const Point& A, const Point& B, const Point& C);
    const Point& getVertex(int index) const;
    void setVertex(int index, const Point& p);
    Segment getSide(int index) const;
    Segment getMedian(int index) const;
    static Point getMidpoint(const Point& p1, const Point& p2);
};

#endif // TRIANGLE_H
