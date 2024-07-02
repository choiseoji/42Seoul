#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

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

PmergeMe::~PmergeMe()
{
    
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

void PmergeMe::fillVec(int size, std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, int flag)
{
    int idx;
    size_t start_idx;

    idx = 0;
    start_idx = 0;
    while (start_idx + (2 * size) < nums.size())
    {
        int cnt;
        std::vector<int> av;
        std::vector<int> bv;

        cnt = 0;
        while (cnt < size)  // 여기 범위 오류 처리 해주기
        {
            av.push_back(nums[idx]);
            idx++;
            cnt++;
        }

        cnt = 0;
        while (cnt < size)  // 여기 범위 오류 처리 해주기
        {
            bv.push_back(nums[idx]);
            idx++;
            cnt++;
        }
        if (flag == 1 && av[0] < bv[0])
            av.swap(bv);
        a.push_back(av);
        b.push_back(bv);
        start_idx += (2 * size);
    }
}

void PmergeMe::makeVec(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b)
{
    int idx = 0;

    for(size_t i = 0; i < a.size(); i++)
    {
        for(size_t j = 0; j < a[i].size(); j++)
        {
            nums[idx] = a[i][j];
            idx++;
        }
        for(size_t j = 0; j < b[i].size(); j++)
        {
            nums[idx] = b[i][j];
            idx++;
        }
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

// 일단 야콥스탈 수열 사용하지 않고 해보기 (B 순서대로 삽입)
void PmergeMe::insertB(int size)
{
    int idx;
    std::vector<std::vector<int> > a;
    std::vector<std::vector<int> > b;

    fillVec(size, a, b, 0);

    // b 들어갈 위치 찾기
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

void PmergeMe::makePair(int size)
{
    std::vector<std::vector<int> > a;
    std::vector<std::vector<int> > b;

    fillVec(size, a, b, 1);
    makeVec(a, b);
}

void PmergeMe::recursive(int size)
{
    if (size * 2 > (int)nums.size())
        return ;

    makePair(size);
    recursive(size * 2);
    insertB(size);
}

void PmergeMe::solve()
{
    nums_print("BEFORE: ");
    recursive(1);
    nums_print("AFTER: ");
}

void PmergeMe::nums_print(std::string str)
{
    std::cout << str;
    for(size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}
