#include "Base.hpp"

int main(void)
{
    Base *ptr;

    ptr = generate();
    identify(ptr);
    identify(*ptr);
    return (0);
}