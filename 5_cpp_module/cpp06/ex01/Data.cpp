#include "Data.hpp"

Data::Data(void) { }

Data::Data(const Data &d)
{
    this->name = d.name;
}

Data& Data::operator=(const Data &d)
{
    if (this != &d)
    {
        this->name = d.name;
    }
    return (*this);
}

Data::~Data(void) { }

void Data::setName(std::string name)
{
    this->name = name;
}

std::string Data::getName(void)
{
    return (this->name);
}
