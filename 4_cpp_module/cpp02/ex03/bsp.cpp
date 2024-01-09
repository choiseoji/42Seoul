#include "Point.hpp"

float get_size(Point p1, Point p2, Point p3)
{
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    float cal1 = (x1 * y2) + (x2 * y3) + (x3 * y1);
    float cal2 = (x2 * y1) + (x3 * y2) + (x1 * y3);
    if (cal1 >= cal2)
        return ((cal1 - cal2) / 2);
    else
        return ((cal2 - cal1) / 2);

}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float total_size = get_size(a, b, c);
    float size1 = get_size(a, b, point);
    float size2 = get_size(a, c, point);
    float size3 = get_size(b, c, point);

    if (total_size == (size1 + size2 + size3))
        return (true);
    else
        return (false);
}