#pragma once
#include "Point.h"

class Shape
{
public:
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;

    virtual bool isPointInside(const Point& point) const = 0;

    virtual Shape* clone() const = 0;

    virtual ~Shape() = default;
};