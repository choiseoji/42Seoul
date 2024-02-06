#include "iter.hpp"

int main(void)
{
    // int형 배열
    int arr[5] = {0, 1, 2, 3, 4};
    iter(arr, sizeof(arr) / sizeof(*arr), printValue);
    std::cout << std::endl;

    // char형 배열
    char arr2[3] = {'a', 'b', 'c'};
    iter(arr2, sizeof(arr2) / sizeof(*arr2), printValue);
    std::cout << std::endl;

    // string형 배열
    std::string arr3[2] = {"cpp07", "ex01"};
    iter(arr3, sizeof(arr3) / sizeof(*arr3), printValue);
    std::cout << std::endl;
}
