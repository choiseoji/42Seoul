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
    // deep copy
    for(int i = 0; i < 4; i++)
    {
        materias[i] = ms.materias[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &ms)
{
    if (this != &ms)
    {
        this->idx = ms.idx;
        // deep copy
        for(int i = 0; i < 4; i++)
        {
            materias[i] = ms.materias[i];
        }
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
    // 배열 돌면서 확인
    for(int i = 0; i < 4; i++)
    {
        if (materias[i]->getType() == type)
        {
            return (materias[i]->clone());    // 새로 생성해서 반환인데 이거 맞나
        }
    }
    return (0);
}
