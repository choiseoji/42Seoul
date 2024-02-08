#include "easyfind.hpp"
#include <vector>
#include <queue>

int main(void)
{
    try
    {
        std::vector<int> v;
        for(int i = 0; i < 10; i++)
        {
            v.push_back(i);
        }
        std::cout << "find idx: " << *(easyfind(v, 2)) << std::endl;
        std::cout << "find idx: " << *(easyfind(v, 99)) << std::endl;


        std::deque<int> dq;
        dq.push_back(100);
        dq.push_back(5);
        dq.push_back(-1);
        std::cout << "find idx: " << *(easyfind(dq, 100)) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
