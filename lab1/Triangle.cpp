#include "Triangle.h"
#include <iostream>

Triangle::Segment::Segment(const Point* pt1, const Point* pt2)
    : p1(pt1), p2(pt2) {
}

void Triangle::Segment::print() const {
    std::cout << "Segment: ";
    p1->print();
    std::cout << " -> ";
    p2->print();
    std::cout << std::endl;
}

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
    vertices[0] = A;
    vertices[1] = B;
    vertices[2] = C;
}

const Point& Triangle::getVertex(int index) const {
    if (index < 0 || index > 2)
        throw std::out_of_range("Index must be between 0 and 2");
    return vertices[index];
}

void Triangle::setVertex(int index, const Point& p) {
    if (index < 0 || index > 2)
        throw std::out_of_range("Index must be between 0 and 2");
    vertices[index] = p;
}

Triangle::Segment Triangle::getSide(int index) const {
    if (index < 0 || index > 2)
        throw std::out_of_range("Index must be between 0 and 2");
    int next = (index + 1) % 3;
    return Segment(&vertices[index], &vertices[next]);
}

Point Triangle::getMidpoint(const Point& p1, const Point& p2) {
    return Point((p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0);
}

Triangle::Segment Triangle::getMedian(int index) const {
    if (index < 0 || index > 2)
        throw std::out_of_range("Index must be between 0 and 2");
    int idx1 = (index + 1) % 3;
    int idx2 = (index + 2) % 3;
    Point midpoint = getMidpoint(vertices[idx1], vertices[idx2]);
    static Point medianEndpoint;
    medianEndpoint = midpoint;
    return Segment(&vertices[index], &medianEndpoint);
}
