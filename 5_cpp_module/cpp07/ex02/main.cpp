#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
    Array<int> arr(3);

    for(int i = 0; i < 3; i++)
    {
        arr[i] = i;
    }
    for(int i = 0; i < 3; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << "size: " << arr.size() << std::endl;

    std::cout << std::endl;

    Array<char> arr2(4);
    for(int i = 0; i < 4; i++)
    {
        arr2[i] = 97 + i;
    }
    for(int i = 0; i < 4; i++)
    {
        std::cout << arr2[i] << std::endl;
    }
    std::cout << "size: " << arr2.size() << std::endl;


    //////////////////////////////////////
    try {
        arr2[5] = 'e';
    } catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
