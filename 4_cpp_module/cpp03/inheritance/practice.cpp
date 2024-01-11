#include <iostream>

// 2차원 평면에서 한 점을 표현하는 클래스
class Point {
private:
	int x, y;

public:
	void set(int x, int y) {this->x = x; this->y = y; }
	void showPoint() {
		std::cout << "x: " << x << " y: " << y << std::endl;
	}
};

// Point 클래스 상속 받는 색 표현하는 자식 클래스
class ColorPoint : public Point {
private:
	std::string color;
public:
	void setColor(std::string color) {this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	std::cout << color << "=> ";
	showPoint();
}

int main(void)
{
	Point p;
	ColorPoint cp;

	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
}
