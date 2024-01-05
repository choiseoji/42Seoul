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
	bool operator==(Power op2);
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

bool Power::operator==(Power op2)
{
	if (this->height == op2.height
		&& this->weight == op2.weight)
		return (true);
	else
		return (false);
}

int main(void)
{
	Power a(160, 50);
	Power b(160, 50);
	Power c(170, 50);

	a.show();
	b.show();
	if (a == b)    // a.operator==(b)
		std::cout << "두 사람의 키와 몸무게는 같다" << std::endl;
	else
		std::cout << "두 사람의 키와 몸무게는 다르다" << std::endl;

	c.show();
	if (a == c)
		std::cout << "두 사람의 키와 몸무게는 같다" << std::endl;
	else
		std::cout << "두 사람의 키와 몸무게는 다르다" << std::endl;
	return (0);
}

