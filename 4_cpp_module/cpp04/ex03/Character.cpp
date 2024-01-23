#include "Character.hpp"

Character::Character(void)
{
    this->idx = 0;
}

Character::Character(std::string name)
{
    this->idx = 0;
    this->name = name;

}

Character::Character(const Character &c)
{
    this->idx = 0;
    this->name = c.name;
    // deep copy
}

Character& Character::operator=(const Character &c)
{
    if (this != &c)
    {
        this->name = name;
        // deep copy
    }
    return (*this);
}

Character::~Character(void)
{

}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (idx < 4)
    {
        inventory[idx] = m;
    }
}

void Character::unequip(int idx)
{
    // 이건 AMateria 지우는건가
}

void Character::use(int idx, ICharacter& target)
{
    // idx에 있는 AMateria 타입보고 출력문 결정해주기
    // ice, cure 상속되어 있으니,,,그걸로 뭐 하면 될 듯
    // Ice: "* shoots an ice bolt at <name> *"
    // Cure: "* heals <name>’s wounds *"
}
