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

void PmergeMe::timePrint()
{
    std::cout << "Time to process a range of " << nums.size() << " elements with std::vector : ";

    std::cout << std::endl;
    std::cout << "Time to process a range of " << nums.size() << " elements with std::deque : ";

    std::cout << std::endl;
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

    // b 들어갈 위치 찾기 -> 여기에 Jacobsthal 수열 적용하기
    for(size_t i = 0; i < pending.size(); i++)
    {
        int idx = binarySearch(mainchain, pending[i][0], 0, mainchain.size() - 1);
        mainchain.insert(mainchain.begin() + idx, pending[i]);
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
