#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    PmergeMe pm;

    pm.setNum(ac, av);

    pm.numsPrint("Before: ");
    pm.recursive(1);
    pm.numsPrint("After: ");
    pm.timePrint();

    return (0);
}