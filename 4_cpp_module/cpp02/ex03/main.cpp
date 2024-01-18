#include "Point.hpp"

int	main(void)
{
	Point a(6.2, 10);
	Point b(2.8, 5.8);
	Point c(9, 5.2);
	Point p(9, 5.2);

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
