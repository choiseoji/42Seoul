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

void PmergeMe::makeVec(std::vector<std::vector<int> > &a)
{
    int idx = 0;

    for(size_t i = 0; i < a.size(); i++)
    {
        for(size_t j = 0; j < a[i].size(); j++)
        {
            nums[idx] = a[i][j];
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

void PmergeMe::fillVec(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, int size)
{
    size_t  start_idx_A;
    size_t  start_idx_B;

    start_idx_A = 0;
    start_idx_B = start_idx_A + size;
    while (start_idx_B + size <= nums.size())
    {
        std::vector<int> tmpA;
        std::vector<int> tmpB;

        tmpA.insert(tmpA.begin(), nums.begin() + start_idx_A, nums.begin() + start_idx_A + size);
        tmpB.insert(tmpB.begin(), nums.begin() + start_idx_B, nums.begin() + start_idx_B + size);
        a.push_back(tmpA);
        b.push_back(tmpB);
        start_idx_A += (2 * size);
        start_idx_B += (2 * size);
    }

    // 남은 애들 다 b에 넣어줘야함
}

void PmergeMe::insertB(int size)
{
    int idx;
    std::vector<std::vector<int> > a;
    std::vector<std::vector<int> > b;

    fillVec(a, b, size);

    // b 들어갈 위치 찾기 -> 여기에 야콥스탈 적용하기
    for(size_t i = 0; i < b.size(); i++)
    {
        idx = binarySearch(a, b[i][0], 0, a.size() - 1);
        a.insert(a.begin() + idx, b[i]);
    }

    if (size == 1 && (nums.size() % 2 == 1))
    {
        std::vector<int> tmp;

        idx = binarySearch(a, nums[nums.size() - 1], 0, a.size() - 1);
        tmp.push_back(nums[nums.size() - 1]);
        a.insert(a.begin() + idx, tmp);
    }
    makeVec(a);
}

void PmergeMe::recursive(int size)
{
    if (size * 2 > (int)nums.size())
        return ;

    sortA(size);
    recursive(size * 2);
    insertB(size);
}
