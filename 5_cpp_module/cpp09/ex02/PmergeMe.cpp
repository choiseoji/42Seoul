#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &pm)
{
    this->nums_vec = pm.nums_vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &pm)
{
    if (this != &pm)
    {
        this->nums_vec = pm.nums_vec;
    }
    return (*this);
}

PmergeMe::~PmergeMe() { }

void PmergeMe::numsPrintVec(std::string str)
{
    std::cout << str;
    for(size_t i = 0; i < nums_vec.size(); i++)
    {
        std::cout << nums_vec[i] << " ";
    }
    std::cout << "\n";
}

void PmergeMe::numsPrintDeq(std::string str)
{
    std::cout << str;
    for(size_t i = 0; i < nums_deq.size(); i++)
    {
        std::cout << nums_deq[i] << " ";
    }
    std::cout << "\n";
}

void PmergeMe::solve(int ac, char *av[])
{
    clock_t start, end;

    setNum(ac, av);
    makeJacobsthalNums();

    // vector solve
    numsPrintVec("Before: ");
    start = clock();

    recursiveVec(1);

    end = clock();
    numsPrintVec("After: ");
    timePrint(start, end, "vector");

    // deque
    numsPrintDeq("Before: ");
    start = clock();

    recursiveDeq(1);

    end = clock();
    numsPrintDeq("After: ");
    timePrint(start, end, "deque");
}

void PmergeMe::timePrint(clock_t start, clock_t end, std::string container)
{
    double timeSpend;

    timeSpend = static_cast<double>((end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << nums_vec.size() << " elements with std::"<< container<<" : "
        << std::fixed << std::setprecision(6) << timeSpend << " us\n";
}

/**
 * error check
 * 1. 인자가 없는 경우
 * 2. positive integer가 아닌 경우
 */
void PmergeMe::setNum(int ac, char *av[])
{
    int     inum;
    double  dnum;
    char    *ptr;
    std::vector<int>::iterator itV;

    // 1.인자가 없는 경우
    if (ac < 2)
        throw std::runtime_error("Error: no argument");
    
    for(int i = 1; i < ac; i++)
    {
        // 2. positive integer가 아닌 경우
        dnum = strtod(av[i], &ptr);
        if (*ptr || dnum > 2147483647 || dnum < 1)
            throw std::runtime_error("Error: not positive integer");

        inum = static_cast<int>(dnum);
        nums_vec.push_back(inum);
        nums_deq.push_back(inum);
    }
}

void PmergeMe::makeJacobsthalNums(void)
{
    jacobsthal_nums.push_back(1);
    jacobsthal_nums.push_back(3);

    int num = 0;
    int p1 = 0;
    int p2 = 1;

    while (num <= static_cast<int> (nums_vec.size()))
    {
        num = jacobsthal_nums[p2] + 2 * jacobsthal_nums[p1];
        jacobsthal_nums.push_back(num);
        p1 ++;
        p2 ++;
    }
}

void PmergeMe::swapVec(int idx1, int idx2, int size)
{
    std::vector<int> big;
    std::vector<int> small;

    big.insert(big.begin(), nums_vec.begin() + idx2, nums_vec.begin() + idx2 + size);
    small.insert(small.begin(), nums_vec.begin() + idx1, nums_vec.begin() + idx1 + size);
    nums_vec.erase(nums_vec.begin() + idx1, nums_vec.begin() + idx2 + size);
    nums_vec.insert(nums_vec.begin() + idx1, big.begin(), big.begin() + size);
    nums_vec.insert(nums_vec.begin() + idx2, small.begin(), small.begin() + size);
}

// pair로 묶어 A, B 구간을 나누는데 항상 A에 더 큰 숫자를 넣도록 한다.
void PmergeMe::sortMainChainVec(int size)
{
    size_t  start_idx_A;
    size_t  start_idx_B;

    start_idx_A = 0;
    start_idx_B = start_idx_A + size;
    while (start_idx_B + size <= nums_vec.size())
    {
        if (nums_vec[start_idx_A] < nums_vec[start_idx_B])
            swapVec(start_idx_A, start_idx_B, size);
        start_idx_A += (2 * size);
        start_idx_B += (2 * size);
    }
}

void PmergeMe::makeNumsVec(std::vector<std::vector<int> > &mainchain)
{
    int idx = 0;

    for(size_t i = 0; i < mainchain.size(); i++)
    {
        for(size_t j = 0; j < mainchain[i].size(); j++)
        {
            nums_vec[idx] = mainchain[i][j];
            idx++;
        }
    }
}

int PmergeMe::binarySearchVec(std::vector<std::vector<int> > &a, int n, int low, int high)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid][0] > n)
            return (binarySearchVec(a, n, low, mid - 1));
        else if (a[mid][0] < n)
            return (binarySearchVec(a, n, mid + 1, high));
        else if (a[mid][0] == n)
            return (mid);
    }
    return (low);
}

void PmergeMe::divNumsVec(std::vector<std::vector<int> > &mainchain, std::vector<std::vector<int> > &pending, int size)
{
    size_t  start_idx_M;
    size_t  start_idx_P;
    std::vector<int> element_of_mainchain;
    std::vector<int> element_of_pending;

    start_idx_M = 0;
    start_idx_P = start_idx_M + size;
    while (start_idx_P + size <= nums_vec.size())
    {
        element_of_mainchain.insert(element_of_mainchain.begin(), 
            nums_vec.begin() + start_idx_M, nums_vec.begin() + start_idx_M + size);
        element_of_pending.insert(element_of_pending.begin(), 
            nums_vec.begin() + start_idx_P, nums_vec.begin() + start_idx_P + size);

        mainchain.push_back(element_of_mainchain);
        pending.push_back(element_of_pending);

        start_idx_M += (2 * size);
        start_idx_P += (2 * size);
        element_of_mainchain.clear();
        element_of_pending.clear();
    }

    // size 하나만큼 수가 남으면 pending에 넣어주기
    if (start_idx_M + size <= nums_vec.size())
    {
        element_of_pending.insert(element_of_pending.begin(), 
            nums_vec.begin() + start_idx_M, nums_vec.begin() + start_idx_M + size);
        pending.push_back(element_of_pending);
    }
}

/**
 * 1. mainchain과 pending으로 나누어주기
 * 2. mainchain에 pending 삽입하여 정렬
 */
void PmergeMe::insertPendingElementsVec(int size)
{
    std::vector<std::vector<int> > mainchain;
    std::vector<std::vector<int> > pending;

    divNumsVec(mainchain, pending, size);

    int cnt = 0;
    int n = 0;
    int st, ed;

    mainchain.insert(mainchain.begin(), pending[0]);
    cnt++;
    while (cnt < static_cast<int> (pending.size()))
    {
        st = jacobsthal_nums[n];
        if (st > static_cast<int> (pending.size() - 1))
            st = pending.size() - 1;
        if (n == 0)
            ed = 0;
        else
            ed = jacobsthal_nums[n - 1];

        while (st > ed)
        {
            int idx = binarySearchVec(mainchain, pending[st][0], 0, mainchain.size() - 1);
            mainchain.insert(mainchain.begin() + idx, pending[st]);
            cnt++;
            st--;
        }
        n++;
    }

    makeNumsVec(mainchain);

}

void PmergeMe::recursiveVec(int size)
{
    if (size * 2 > (int)nums_vec.size())
        return ;

    sortMainChainVec(size);
    recursiveVec(size * 2);
    insertPendingElementsVec(size);
}

///////////////////////////////////////////////////////////////////

void PmergeMe::swapDeq(int idx1, int idx2, int size)
{
    std::deque<int> big;
    std::deque<int> small;

    big.insert(big.begin(), nums_deq.begin() + idx2, nums_deq.begin() + idx2 + size);
    small.insert(small.begin(), nums_deq.begin() + idx1, nums_deq.begin() + idx1 + size);
    nums_deq.erase(nums_deq.begin() + idx1, nums_deq.begin() + idx2 + size);
    nums_deq.insert(nums_deq.begin() + idx1, big.begin(), big.begin() + size);
    nums_deq.insert(nums_deq.begin() + idx2, small.begin(), small.begin() + size);
}

// pair로 묶어 A, B 구간을 나누는데 항상 A에 더 큰 숫자를 넣도록 한다.
void PmergeMe::sortMainChainDeq(int size)
{
    size_t  start_idx_A;
    size_t  start_idx_B;

    start_idx_A = 0;
    start_idx_B = start_idx_A + size;
    while (start_idx_B + size <= nums_deq.size())
    {
        if (nums_deq[start_idx_A] < nums_deq[start_idx_B])
            swapDeq(start_idx_A, start_idx_B, size);
        start_idx_A += (2 * size);
        start_idx_B += (2 * size);
    }
}

void PmergeMe::makeNumsDeq(std::deque<std::deque<int> > &mainchain)
{
    int idx = 0;

    for(size_t i = 0; i < mainchain.size(); i++)
    {
        for(size_t j = 0; j < mainchain[i].size(); j++)
        {
            nums_deq[idx] = mainchain[i][j];
            idx++;
        }
    }
}

int PmergeMe::binarySearchDeq(std::deque<std::deque<int> > &a, int n, int low, int high)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid][0] > n)
            return (binarySearchDeq(a, n, low, mid - 1));
        else if (a[mid][0] < n)
            return (binarySearchDeq(a, n, mid + 1, high));
        else if (a[mid][0] == n)
            return (mid);
    }
    return (low);
}

void PmergeMe::divNumsDeq(std::deque<std::deque<int> > &mainchain, std::deque<std::deque<int> > &pending, int size)
{
    size_t  start_idx_M;
    size_t  start_idx_P;
    std::deque<int> element_of_mainchain;
    std::deque<int> element_of_pending;

    start_idx_M = 0;
    start_idx_P = start_idx_M + size;
    while (start_idx_P + size <= nums_deq.size())
    {
        element_of_mainchain.insert(element_of_mainchain.begin(), 
            nums_deq.begin() + start_idx_M, nums_deq.begin() + start_idx_M + size);
        element_of_pending.insert(element_of_pending.begin(), 
            nums_deq.begin() + start_idx_P, nums_deq.begin() + start_idx_P + size);

        mainchain.push_back(element_of_mainchain);
        pending.push_back(element_of_pending);

        start_idx_M += (2 * size);
        start_idx_P += (2 * size);
        element_of_mainchain.clear();
        element_of_pending.clear();
    }

    // size 하나만큼 수가 남으면 pending에 넣어주기
    if (start_idx_M + size <= nums_deq.size())
    {
        element_of_pending.insert(element_of_pending.begin(), 
            nums_deq.begin() + start_idx_M, nums_deq.begin() + start_idx_M + size);
        pending.push_back(element_of_pending);
    }
}

/**
 * 1. mainchain과 pending으로 나누어주기
 * 2. mainchain에 pending 삽입하여 정렬
 */
void PmergeMe::insertPendingElementsDeq(int size)
{
    std::deque<std::deque<int> > mainchain;
    std::deque<std::deque<int> > pending;

    divNumsDeq(mainchain, pending, size);

    int cnt = 0;
    int n = 0;
    int st, ed;

    mainchain.insert(mainchain.begin(), pending[0]);
    cnt++;
    while (cnt < static_cast<int> (pending.size()))
    {
        st = jacobsthal_nums[n];
        if (st > static_cast<int> (pending.size() - 1))
            st = pending.size() - 1;
        if (n == 0)
            ed = 0;
        else
            ed = jacobsthal_nums[n - 1];

        while (st > ed)
        {
            int idx = binarySearchDeq(mainchain, pending[st][0], 0, mainchain.size() - 1);
            mainchain.insert(mainchain.begin() + idx, pending[st]);
            cnt++;
            st--;
        }
        n++;
    }

    makeNumsDeq(mainchain);
}

void PmergeMe::recursiveDeq(int size)
{
    if (size * 2 > (int)nums_deq.size())
        return ;

    sortMainChainDeq(size);
    recursiveDeq(size * 2);
    insertPendingElementsDeq(size);
}
