#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
    this->nums = pm.nums;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &pm)
{
    if (this != &pm)
    {
        this->nums = pm.nums;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
    
}

void PmergeMe::setNum(int ac, char *av[])
{
    int num;

    for(int i = 1; i < ac; i++)
    {
        num = strtod(av[i], NULL);
        nums.push_back(num);
    }
}
