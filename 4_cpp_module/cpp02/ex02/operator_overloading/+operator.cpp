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
	Power operator+(Power op2);
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

Power	Power::operator+(Power op2)
{
	Power	tmp;

	tmp.height = this->height + op2.height;
	tmp.weight = this->weight + op2.weight;
	return (tmp);
}

int main(void)
{
	Power a(160, 50);
	Power b(170, 60);
	Power c;

	c = a + b;   // 객체끼리 + 연산  -> c = a.operator+(b)
	a.show();
	b.show();
	c.show();

	return (0);
}
