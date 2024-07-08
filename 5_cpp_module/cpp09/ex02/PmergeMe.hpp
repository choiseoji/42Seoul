#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
private:
    std::vector<int> nums;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &pm);
    PmergeMe& operator=(const PmergeMe &pm);
    ~PmergeMe();

    void setNum(int ac, char *av[]);
    void numsPrint(std::string str);
    void timePrint();

    // vector
    void sortA(int size);
    void recursive(int size);
    void insertB(int size);

    void swapVec(int idx1, int idx2, int size);
    void divNums(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, int size);
    int binarySearch(std::vector<std::vector<int> > &a, int n, int low, int high);
    void makeNums(std::vector<std::vector<int> > &mainchain);
    
    // deque

};

#endif