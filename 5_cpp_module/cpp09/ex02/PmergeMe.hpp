#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>

class PmergeMe
{
private:
    int size;
    std::vector<int> nums;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &pm);
    PmergeMe& operator=(const PmergeMe &pm);
    ~PmergeMe();

    void setNum(int ac, char *av[]);
};

#endif