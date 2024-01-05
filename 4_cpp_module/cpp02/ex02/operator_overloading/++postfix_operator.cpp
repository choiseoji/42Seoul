#include <iostream>

class Power
{
private:
	int height;
	int weight;

public:
	Power();
	Power(int h, int w);

	void show();
	Power operator++(int x);  // 후위 연산자는 의미없는 매개변수를 가진다
};

Power::Power(void) { }

Power::Power(int h, int w)
{
	this->height = h;
	this->weight = w;
}

void	Power::show(void)
{
	std::cout << "height: " << this->height << "  weight: " << this->weight << std::endl;
}

Power Power::operator++(int x)
{
	Power tmp = *this;     // 증가 전의 객체 저장

	this->height++;  // a객체 값 증가시키기
	this->weight++;
	return (tmp);
}

int main(void)
{
	Power a(160, 50);
	Power b;

	a.show();
	b.show();
	b = a++;
	a.show();
	b.show();
	return (0);
}
