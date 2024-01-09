#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {

private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &p);
    Point& operator=(const Point &p);
    ~Point();

    Fixed getX();
    Fixed getY();
};

float get_size(Point p1, Point p2, Point p3);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif