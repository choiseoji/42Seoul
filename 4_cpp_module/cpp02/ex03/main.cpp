#include "Point.hpp"

int	main(void)
{
	Point a(0.16, 2.08);
	Point b(0.34, 2.28);
	Point c(0.52, 2.02);
	Point p(0.20, 2.22);

	std::cout << "a 좌표" << std::endl;
	std::cout << "x: " << a.getX() << " y: " << a.getY() << std::endl;
	std::cout << "b 좌표" << std::endl;
	std::cout << "x: " << b.getX() << " y: " << b.getY() << std::endl;
	std::cout << "c 좌표" << std::endl;
	std::cout << "x: " << c.getX() << " y: " << c.getY() << std::endl;
	std::cout << "p 좌표" << std::endl;
	std::cout << "x: " << p.getX() << " y: " << p.getY() << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "point is inside of a triangle" << std::endl;
	else
		std::cout << "point is not inside of a triangle" << std::endl;
	return (0);
}