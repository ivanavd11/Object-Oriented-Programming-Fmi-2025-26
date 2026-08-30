#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
    Point bottomLeft;
    double width;
    double height;

public:
    Rectangle(const Point& bottomLeft,double width,double height);

    void setBottomLeft(const Point& newBottomLeft);
    void setWidth(double newWidth);
    void setHeight(double newHeight);

    const Point& getBottomLeft() const;
    double getWidth() const;
    double getHeight() const;

    double getPerimeter() const override;
    double getArea() const override;

    bool isPointInside(const Point& point) const override;

    Shape* clone() const override;
};

#endif
