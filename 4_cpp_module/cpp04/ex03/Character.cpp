#include "Character.hpp"
#include "Floor.hpp"

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
    for(int i = 0; i < 4; i++)
    {
        if (c.inventory[i])
            inventory[i] = c.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(const Character &c)
{
    if (this != &c)
    {
        this->name = c.name;
        for(int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (c.inventory[i])
                inventory[i] = c.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return (*this);
}

Character::~Character(void)
{
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = m;
            return ;
        }
    }
    std::cout << "There is no space to equip it" << std::endl;
}

void Character::unequip(int idx)
{
    if (checkIdx(idx) && checkIsExist(idx))
    {
        
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (checkIdx(idx) && checkIsExist(idx))
        inventory[idx]->use(target);
}

int Character::checkIdx(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "You can only have index values from 0 to 3" << std::endl;
        return (0);
    }
    return (1);
}

int Character::checkIsExist(int idx)
{
    if (inventory[idx] == 0)
    {
        std::cout << "It's a non-existent Materia" << std::endl;
        return (0);
    }
    return (1);
}
