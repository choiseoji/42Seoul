#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) { }

AMateria::AMateria(const AMateria &a)
{
    this->type = a.type;
}

AMateria& AMateria::operator=(const AMateria &a)
{
    if (this != &a)
    {
        this->type = a.type;
    }
    return (*this);
}

AMateria::~AMateria(void) { }

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

std::string const & AMateria::getType(void) const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << std::endl;
}
