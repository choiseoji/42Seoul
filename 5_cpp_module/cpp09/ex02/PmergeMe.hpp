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

    // parsing
    void setNum(int ac, char *av[]);

    // solve
    void solve();

    void makePair(int size);

    void makeVec(std::vector<std::deque<int> > &a, std::vector<std::deque<int> > &b);
    void makeVec2(std::vector<std::deque<int> > &a);
    
    void fillVec(int size, std::vector<std::deque<int> > &a, std::vector<std::deque<int> > &, int flag);
    
    void recursive(int size);
    void insertB(int size);
    int binarySearch(std::vector<std::deque<int> > &a, int n, int low, int high);

    // print
    void nums_print(std::string str);
};

#endif