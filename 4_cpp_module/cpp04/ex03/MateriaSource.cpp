#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    this->idx = 0;
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    this->idx = ms.idx;
    // deep copy
}

MateriaSource& MateriaSource::operator=(const MateriaSource &ms)
{
    if (this != &ms)
    {
        this->idx = ms.idx;
        // deep copy
    }
    return (*this);
}

MateriaSource::~MateriaSource(void) { }

void MateriaSource::learnMateria(AMateria* m)
{
    // learnMateria는 저장하는 거??
    if (idx < 4)
    {
        materias[idx] = m;
        idx++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // createMateria는 새로 생성해서 반환
}
