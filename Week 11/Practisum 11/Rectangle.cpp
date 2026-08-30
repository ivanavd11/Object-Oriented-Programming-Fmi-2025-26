#include "Rectangle.h"

#include "Rectangle.h"

#include <stdexcept>

Rectangle::Rectangle( const Point& bottomLeft, double width,double height)
    : bottomLeft(bottomLeft), width(width), height(height)
{
    if (width <= 0 || height <= 0) 
    {
        throw std::invalid_argument("Width and height must be positive.");
    }
}

void Rectangle::setBottomLeft(const Point& newBottomLeft) 
{
    bottomLeft = newBottomLeft;
}

void Rectangle::setWidth(double newWidth) 
{
    if (newWidth <= 0) 
    {
        throw std::invalid_argument("Width must be positive.");
    }

    width = newWidth;
}

void Rectangle::setHeight(double newHeight) 
{
    if (newHeight <= 0) 
    {
        throw std::invalid_argument("Height must be positive.");
    }

    height = newHeight;
}

const Point& Rectangle::getBottomLeft() const 
{
    return bottomLeft;
}

double Rectangle::getWidth() const 
{
    return width;
}

double Rectangle::getHeight() const 
{
    return height;
}

double Rectangle::getPerimeter() const 
{
    return 2 * (width + height);
}

double Rectangle::getArea() const 
{
    return width * height;
}

bool Rectangle::isPointInside( const Point& point) const 
{
    double left = bottomLeft.getX();
    double right = left + width;

    double bottom = bottomLeft.getY();
    double top = bottom + height;

    return point.getX() >= left &&
        point.getX() <= right &&
        point.getY() >= bottom &&
        point.getY() <= top;
}

Shape* Rectangle::clone() const 
{
    return new Rectangle(*this);
}