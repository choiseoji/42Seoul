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

    void numsPrint(std::string str);
    void setNum(int ac, char *av[]);
    void swapVec(int idx1, int idx2, int size);
    void recursive(int size);
    void sortA(int size);
    void makeVec(std::vector<std::vector<int> > &a);
    int binarySearch(std::vector<std::vector<int> > &a, int n, int low, int high);
    void fillVec(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, int size);
    void insertB(int size);

};

#endif