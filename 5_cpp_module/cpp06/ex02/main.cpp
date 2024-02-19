#include "Base.hpp"

int main(void)
{
    srand(time(0));
    {
        Base *ptr;

        ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }

    {
        Base *ptr2;

        ptr2 = generate();
        identify(ptr2);
        identify(*ptr2);
        delete ptr2;
    }
    return (0);
}
