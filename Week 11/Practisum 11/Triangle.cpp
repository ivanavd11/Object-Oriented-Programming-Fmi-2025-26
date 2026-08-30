#include "Triangle.h"

#include <cmath>
#include <stdexcept>

namespace {
    constexpr double EPSILON = 0.000000001;
}

Triangle::Triangle(const Point& a,const Point& b,const Point& c)
    : a(a), b(b), c(c) {

    validate();
}

double Triangle::getSignedArea(const Point& p1,const Point& p2,const Point& p3) {
    return (
        p1.getX() * (p2.getY() - p3.getY()) +
        p2.getX() * (p3.getY() - p1.getY()) +
        p3.getX() * (p1.getY() - p2.getY())
        ) / 2.0;
}

void Triangle::validate() const {
    if (std::abs(getSignedArea(a, b, c)) < EPSILON) {
        throw std::invalid_argument(
            "The points do not form a triangle."
        );
    }
}

void Triangle::setA(const Point& newA) {
    Point oldA = a;
    a = newA;

    try {
        validate();
    }
    catch (...) {
        a = oldA;
        throw;
    }
}

void Triangle::setB(const Point& newB) {
    Point oldB = b;
    b = newB;

    try {
        validate();
    }
    catch (...) {
        b = oldB;
        throw;
    }
}

void Triangle::setC(const Point& newC) {
    Point oldC = c;
    c = newC;

    try {
        validate();
    }
    catch (...) {
        c = oldC;
        throw;
    }
}

const Point& Triangle::getA() const 
{
    return a;
}

const Point& Triangle::getB() const 
{
    return b;
}

const Point& Triangle::getC() const
{
    return c;
}

double Triangle::getPerimeter() const 
{
    return Point::getDistance(a, b) +
        Point::getDistance(b, c) +
        Point::getDistance(c, a);
}

double Triangle::getArea() const 
{
    return std::abs(getSignedArea(a, b, c));
}

bool Triangle::isPointInside(const Point& point) const 
{
    double area1 = getSignedArea(a, b, point);
    double area2 = getSignedArea(b, c, point);
    double area3 = getSignedArea(c, a, point);

    bool hasNegative =
        area1 < -EPSILON ||
        area2 < -EPSILON ||
        area3 < -EPSILON;

    bool hasPositive =
        area1 > EPSILON ||
        area2 > EPSILON ||
        area3 > EPSILON;

    return !(hasNegative && hasPositive);
}

Shape* Triangle::clone() const 
{
    return new Triangle(*this);
}