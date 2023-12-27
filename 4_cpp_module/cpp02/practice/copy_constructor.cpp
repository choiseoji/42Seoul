#include <iostream>

class Circle {
private:
	int radius;
public:
	Circle(const Circle &c);  // 복사 생성자
	Circle() {radius = 1; }
	Circle(int radius) {this->radius = radius; }
	double getArea() {return 3.14 * radius * radius; }
};

Circle::Circle(const Circle &c)   // 복사 생성자 구현
{
	this->radius = c.radius;
	std::cout << "복사 생성자 실행 radius = " << radius << std::endl;
}

int main(void)
{
	Circle src(30);   // src 객체의 보통 생성자 호출
	Circle dst(src);  // dst 객체의 복사 생성자 호출

	std::cout << "원본의 면적 = " << src.getArea() << std::endl;
	std::cout << "사본의 면적 = " << dst.getArea() << std::endl;
	return (0);
}
