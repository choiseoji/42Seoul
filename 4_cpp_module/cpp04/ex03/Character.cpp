#include "Character.hpp"

Character::Character(void)
{
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = 0;
    }
}

Character::Character(std::string name)
{
    this->name = name;
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = 0;
    }
}

Character::Character(const Character &c)
{
    this->name = c.name;
    // deep copy : 이렇게 하면 되나
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = c.inventory[i];
    }
}

Character& Character::operator=(const Character &c)
{
    if (this != &c)
    {
        this->name = c.name;
        // deep copy
        for(int i = 0; i < 4; i++)
        {
            inventory[i] = c.inventory[i];
        }
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
    // unequip 때문에 이렇게 하면 안될듯..
    // 배열 돌면서 비워져 있는 자리에 삽입
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    // 해당 idx에 있는거 지우는 거인듯..
    // 이건 AMateria 지우는건가
    inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    // idx에 있는 AMateria 타입보고 출력문 결정해주기
    // ice, cure 상속되어 있으니,,,그걸로 뭐 하면 될 듯
    // Ice: "* shoots an ice bolt at <name> *"
    // Cure: "* heals <name>’s wounds *"
    inventory[idx]->use(target);
}
