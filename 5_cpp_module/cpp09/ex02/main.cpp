#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    PmergeMe pm;

    pm.setNum(ac, av);
    pm.recursive(1);

    return (0);
}