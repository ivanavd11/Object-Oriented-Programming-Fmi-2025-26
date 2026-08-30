#pragma once
#include "Shape.h"


class Circle :public Shape
{
private:
	Point center;
	double radius;

public:
    Circle(const Point& center, double radius);

    void setCenter(const Point& newCenter);
    void setRadius(double newRadius);

    const Point& getCenter() const;
    double getRadius() const;

    double getPerimeter() const override;
    double getArea() const override;

    bool isPointInside(const Point& point) const override;

    Shape* clone() const override;
};
