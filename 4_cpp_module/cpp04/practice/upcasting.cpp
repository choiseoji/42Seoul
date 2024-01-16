#include <iostream>

class Base
{
public:
	void print_base(void)
	{
		std::cout << "is base\n";
	}
};

class Derived : public Base
{
public:
	void print_derived(void)
	{
		std::cout << "is_derived\n";
	}
};

int main(void)
{
	Derived d;
	Derived *pd = &d;
	Base	*pb = pd;    // 업캐스팅 : 상위 클래스의 객체 포인터가 하위 클래스 객체 주소를 가리키고 있음


	// 하지만 타입은 Base 이므로 Base 멤버에만 접근 가능
	pb->print_base();
	// pb->print_drived();   // 오류
	return (0);
}
