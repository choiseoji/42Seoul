#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    PmergeMe pm;

    pm.setNum(ac, av);
    pm.solve();

    return (0);
}