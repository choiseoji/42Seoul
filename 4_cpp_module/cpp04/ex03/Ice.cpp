#include "Ice.hpp"

Ice::Ice(void) { }

Ice::Ice(const Ice &ice)
{

}

Ice& Ice::operator=(const Ice &ice)
{
    if (this != &ice)
    {

    }
    return (*this);
}

Ice::~Ice(void) { }

void Ice::setType(void)
{
    this->type = "ice";
}

std::string const & Ice::getType()
{
    return (this->type);
}

AMateria* Ice::clone(void) const
{
    // clone
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
