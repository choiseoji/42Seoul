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
	Power& operator++();
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

Power&	Power::operator++(void)
{
	this->height++;
	this->weight++;
	return (*this);
}

int main(void)
{
	Power a(160, 50);
	Power b;

	a.show();
	b.show();
	b = ++a;   // a.operator++();
	a.show();
	b.show();
	return (0);
}

