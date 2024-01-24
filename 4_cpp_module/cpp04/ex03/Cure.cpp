#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure(void)
{
    this->type = "cure";
}

Cure::Cure(const Cure &cure)
{
    this->type = cure.type;
}

Cure& Cure::operator=(const Cure &cure)
{
    if (this != &cure)
    {
        this->type = cure.type;
    }
    return (*this);
}

Cure::~Cure(void) { }

std::string const & Cure::getType(void)
{
    return (this->type);
}

AMateria* Cure::clone(void) const
{
    AMateria* nc = new Cure();
    return (nc);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}