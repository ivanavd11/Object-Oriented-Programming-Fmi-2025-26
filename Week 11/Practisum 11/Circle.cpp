#include "Circle.h"

namespace 
{
    constexpr double PI = 3.14159265358979323846;
}

Circle::Circle(const Point& center, double radius)
    :center(center), radius(radius)
{
    if (radius <= 0)
    {
        std::cout << "Invalid radius\n";
    }
}

void Circle::setCenter(const Point& newCenter)
{
    center = newCenter;
}
void Circle::setRadius(double newRadius)
{
    if (newRadius <= 0)
    {
        std::cout << "Invalid radius\n";
        return;
    }
    radius = newRadius;
}

const Point& Circle::getCenter() const
{
    return center;
}
double Circle::getRadius() const
{
    return radius;
}

double Circle::getPerimeter() const 
{
    return 2 * radius * PI;
}
double Circle::getArea() const
{
    return radius * radius * PI;
}

bool Circle::isPointInside(const Point& point) const
{
    return Point::getDistance(center, point) <= radius;
}

Shape* Circle::clone() const
{
    return new Circle(*this);
}