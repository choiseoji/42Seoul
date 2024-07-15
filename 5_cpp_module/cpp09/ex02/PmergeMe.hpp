#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <time.h>
# include <iomanip>

class PmergeMe
{
private:
    std::vector<int> nums;
    std::vector<int> jacobsthal_nums;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &pm);
    PmergeMe& operator=(const PmergeMe &pm);
    ~PmergeMe();

    void solve(int ac, char *av[]);
    void setNum(int ac, char *av[]);
    void numsPrint(std::string str);
    void timePrint(clock_t start, clock_t end, std::string container);

    // vector
    void sortA(int size);
    void recursive(int size);
    void insertB(int size);

    void makeJacobsthalNums();
    void swapVec(int idx1, int idx2, int size);
    void divNums(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, int size);
    int binarySearch(std::vector<std::vector<int> > &a, int n, int low, int high);
    void makeNums(std::vector<std::vector<int> > &mainchain);
    // deque

};

#endif