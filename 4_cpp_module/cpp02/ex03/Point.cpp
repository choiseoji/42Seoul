#include "Point.hpp"

Point::Point(void) : x(0), y(0) { }

Point::Point(const float x, const float y) : x(x), y(y) { }

Point::Point(const Point &p) : x(p.x), y(p.y) { }

Point& Point::operator=(const Point &p)
{
    if (this != &p)
    {

    }
    return (*this);
}

Point::~Point(void) { }

Fixed Point::getX(void)
{
    return (x);
}

Fixed Point::getY(void)
{
    return (y);
}
