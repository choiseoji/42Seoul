#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice(void)
{
    this->type = "ice";
}

Ice::Ice(const Ice &ice)
{
    this->type = ice.type;
}

Ice& Ice::operator=(const Ice &ice)
{
    if (this != &ice)
    {
        this->type = ice.type;
    }
    return (*this);
}

Ice::~Ice(void) { }

std::string const & Ice::getType()
{
    return (this->type);
}

AMateria* Ice::clone(void) const
{
    AMateria* ni = new Ice();
    return (ni);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
