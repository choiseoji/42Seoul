#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    PmergeMe pm;

    pm.setNum(ac, av);

    pm.numsPrint("BEFORE: ");
    pm.recursive(1);
    pm.numsPrint("AFTER: ");

    return (0);
}