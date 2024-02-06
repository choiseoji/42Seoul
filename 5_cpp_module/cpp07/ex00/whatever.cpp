#include "whatever.hpp"

Whatever::Whatever(void) { }

Whatever::Whatever(const Whatever &w)
{
    (void)w;
}

Whatever& Whatever::operator=(const Whatever &w)
{
    if (this != &w)
    {

    }
    return (*this);
}

Whatever::~Whatever() { }