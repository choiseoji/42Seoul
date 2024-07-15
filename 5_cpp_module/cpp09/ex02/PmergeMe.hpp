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
    std::vector<int> nums_vec;
    std::deque<int> nums_deq;

    std::vector<int> jacobsthal_nums;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &pm);
    PmergeMe& operator=(const PmergeMe &pm);
    ~PmergeMe();

    void solve(int ac, char *av[]);
    void setNum(int ac, char *av[]);
    void timePrint(clock_t start, clock_t end, std::string container);
    void makeJacobsthalNums();

    // vector
    void sortMainChainVec(int size);
    void recursiveVec(int size);
    void insertPendingElementsVec(int size);

    void numsPrintVec(std::string str);
    void swapVec(int idx1, int idx2, int size);
    void divNumsVec(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, int size);
    int binarySearchVec(std::vector<std::vector<int> > &a, int n, int low, int high);
    void makeNumsVec(std::vector<std::vector<int> > &mainchain);
    
    // deque
    void sortMainChainDeq(int size);
    void recursiveDeq(int size);
    void insertPendingElementsDeq(int size);

    void numsPrintDeq(std::string str);
    void swapDeq(int idx1, int idx2, int size);
    void divNumsDeq(std::deque<std::deque<int> > &a, std::deque<std::deque<int> > &b, int size);
    int binarySearchDeq(std::deque<std::deque<int> > &a, int n, int low, int high);
    void makeNumsDeq(std::deque<std::deque<int> > &mainchain);

};

#endif