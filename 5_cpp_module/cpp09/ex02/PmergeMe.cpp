#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

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

PmergeMe::~PmergeMe() { }

void PmergeMe::numsPrint(std::string str)
{
    std::cout << str;
    for(size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}

void PmergeMe::solve(int ac, char *av[])
{
    clock_t start, end;

    setNum(ac, av);
    makeJacobsthalNums();

    // vector solve
    numsPrint("Before: ");
    start = clock();

    recursive(1);

    end = clock();
    numsPrint("After: ");
    timePrint(start, end, "vector");

    // deque
}

void PmergeMe::timePrint(clock_t start, clock_t end, std::string container)
{
    double timeSpend;

    timeSpend = static_cast<double>((end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << nums.size() << " elements with std::"<< container<<" : "
        << std::fixed << std::setprecision(6) << timeSpend << " us\n";
}

/**
 * error check
 * 1. 인자가 없는 경우
 * 2. positive integer가 아닌 경우
 * 3. dup num인 경우
 */
void PmergeMe::setNum(int ac, char *av[])
{
    int    inum;
    double dnum;
    std::vector<int>::iterator it;

    // 1.인자가 없는 경우
    if (ac < 2)
        throw std::runtime_error("Error: no argument");
    
    for(int i = 1; i < ac; i++)
    {
        // 2. positive integer가 아닌 경우
        dnum = strtod(av[i], NULL);
        if (dnum > 2147483647 || dnum < 0)
            throw std::runtime_error("Error: not positive integer");

        // 3. dup num인 경우
        inum = static_cast<int>(dnum);
        it = find(nums.begin(), nums.end(), inum);
        if (it != nums.end())
            throw std::runtime_error("Error: dup num");
        nums.push_back(inum);
    }
}

void PmergeMe::makeJacobsthalNums(void)
{
    jacobsthal_nums.push_back(1);
    jacobsthal_nums.push_back(3);

    int num = 0;
    int p1 = 0;
    int p2 = 1;

    while (num <= static_cast<int> (nums.size()))
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

    big.insert(big.begin(), nums.begin() + idx2, nums.begin() + idx2 + size);
    small.insert(small.begin(), nums.begin() + idx1, nums.begin() + idx1 + size);
    nums.erase(nums.begin() + idx1, nums.begin() + idx2 + size);
    nums.insert(nums.begin() + idx1, big.begin(), big.begin() + size);
    nums.insert(nums.begin() + idx2, small.begin(), small.begin() + size);
}

// pair로 묶어 A, B 구간을 나누는데 항상 A에 더 큰 숫자를 넣도록 한다.
void PmergeMe::sortA(int size)
{
    size_t  start_idx_A;
    size_t  start_idx_B;

    start_idx_A = 0;
    start_idx_B = start_idx_A + size;
    while (start_idx_B + size <= nums.size())
    {
        if (nums[start_idx_A] < nums[start_idx_B])
            swapVec(start_idx_A, start_idx_B, size);
        start_idx_A += (2 * size);
        start_idx_B += (2 * size);
    }
}

void PmergeMe::makeNums(std::vector<std::vector<int> > &mainchain)
{
    int idx = 0;

    for(size_t i = 0; i < mainchain.size(); i++)
    {
        for(size_t j = 0; j < mainchain[i].size(); j++)
        {
            nums[idx] = mainchain[i][j];
            idx++;
        }
    }
}

int PmergeMe::binarySearch(std::vector<std::vector<int> > &a, int n, int low, int high)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid][0] > n)
            return (binarySearch(a, n, low, mid - 1));
        else if (a[mid][0] < n)
            return (binarySearch(a, n, mid + 1, high));
    }
    return (low);
}

void PmergeMe::divNums(std::vector<std::vector<int> > &mainchain, std::vector<std::vector<int> > &pending, int size)
{
    size_t  start_idx_M;
    size_t  start_idx_P;
    std::vector<int> element_of_mainchain;
    std::vector<int> element_of_pending;

    start_idx_M = 0;
    start_idx_P = start_idx_M + size;
    while (start_idx_P + size <= nums.size())
    {
        element_of_mainchain.insert(element_of_mainchain.begin(), 
            nums.begin() + start_idx_M, nums.begin() + start_idx_M + size);
        element_of_pending.insert(element_of_pending.begin(), 
            nums.begin() + start_idx_P, nums.begin() + start_idx_P + size);

        mainchain.push_back(element_of_mainchain);
        pending.push_back(element_of_pending);

        start_idx_M += (2 * size);
        start_idx_P += (2 * size);
        element_of_mainchain.clear();
        element_of_pending.clear();
    }

    // size 하나만큼 수가 남으면 pending에 넣어주기
    if (start_idx_M + size <= nums.size())
    {
        element_of_pending.insert(element_of_pending.begin(), nums.begin() + start_idx_M, nums.begin() + start_idx_M + size);
        pending.push_back(element_of_pending);
    }
}

/**
 * 1. mainchain과 pending으로 나누어주기
 * 2. mainchain에 pending 삽입하여 정렬
 */
void PmergeMe::insertB(int size)
{
    std::vector<std::vector<int> > mainchain;
    std::vector<std::vector<int> > pending;

    divNums(mainchain, pending, size);

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
            int idx = binarySearch(mainchain, pending[st][0], 0, mainchain.size() - 1);
            mainchain.insert(mainchain.begin() + idx, pending[st]);
            cnt++;
            st--;
        }
        n++;
    }

    makeNums(mainchain);
}

void PmergeMe::recursive(int size)
{
    if (size * 2 > (int)nums.size())
        return ;

    sortA(size);
    recursive(size * 2);
    insertB(size);
}
