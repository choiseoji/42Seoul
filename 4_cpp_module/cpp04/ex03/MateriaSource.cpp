#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    this->idx = 0;
    for(int i = 0; i < 4; i++)
    {
        materias[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    this->idx = ms.idx;
    for(int i = 0; i < 4; i++)
    {
        if (ms.materias[i])
            materias[i] = ms.materias[i]->clone();
        else
            materias[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &ms)
{
    if (this != &ms)
    {
        this->idx = ms.idx;
        for(int i = 0; i < 4; i++)
        {
            if (materias[i])
                delete materias[i];
            if (ms.materias[i])
                materias[i] = ms.materias[i]->clone();
            else
                materias[i] = 0;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    for(int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (idx < 4)
    {
        materias[idx] = m;
        idx++;
    }
    else
    {
        delete m;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; i++)
    {
        if (materias[i]->getType() == type)
        {
            return (materias[i]->clone());
        }
    }
    return (0);
}
