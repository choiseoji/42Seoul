#include "Floor.hpp"

int Floor::size = 0;
AMateria **Floor::list = nullptr;

Floor::Floor(void) { }

Floor::Floor(const Floor &f)
{
    size = f.size;

    list = new AMateria*[size];
    for (int i = 0; i < size; ++i)
    {
        list[i] = f.list[i]->clone();
    }
}

Floor& Floor::operator=(const Floor &f)
{
    if (this != &f)
    {
        size = f.size;
        for (int i = 0; i < size; ++i)
        {
            delete list[i];
        }
        delete[] list;
        list = new AMateria*[size];
        for (int i = 0; i < size; ++i)
        {
            list[i] = f.list[i]->clone();
        }
    }
    return (*this);
}

Floor::~Floor(void)
{
    for(int i = 0; i < size; i++)
    {
        delete list[i];
    }
    delete []list;
}

void Floor::set_list(AMateria *a)
{
    AMateria **new_list;

    new_list = new AMateria*[size + 1];
    for(int i = 0; i < size; i++)
    {
        new_list[i] = list[i];
    }
    new_list[size] = a;

    delete []list;
    list = new_list;
    size += 1;
}
