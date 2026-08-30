#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    Point a;
    Point b;
    Point c;

    static double getSignedArea(const Point& p1,const Point& p2,const Point& p3);

    void validate() const;

public:
    Triangle(const Point& a,const Point& b, const Point& c);

    void setA(const Point& newA);
    void setB(const Point& newB);
    void setC(const Point& newC);

    const Point& getA() const;
    const Point& getB() const;
    const Point& getC() const;

    double getPerimeter() const override;
    double getArea() const override;

    bool isPointInside(const Point& point) const override;

    Shape* clone() const override;
};

#endif
