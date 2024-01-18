#include <iostream>

class ConstPr
{
public:
	void print() const;
	void print();
};

void ConstPr::print(void) const
{
	std::cout << "is const func" << std::endl;
}

void ConstPr::print(void)
{
	std::cout << "is normal func" << std::endl;
}

int main(void)
{
	ConstPr a;
	const ConstPr b;

	a.print();
	b.print();

	return (0);
}
