#include <iostream>

class Base
{
public:
	virtual void print(void)
	{
		std::cout << "is base\n";
	}
};

class Derived : public Base
{
public:
	void print(void) override
	{
		std::cout << "is_derived\n";   // 가상 함수 오버라이딩
	}
};

int main(void)
{
	Derived d;
	Derived *pd = &d;
	Base	*pb = pd;

	pb->print();    // 출력 결과 : is_derived

	return (0);
}
