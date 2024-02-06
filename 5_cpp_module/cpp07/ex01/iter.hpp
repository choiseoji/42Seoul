#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void printValue(T value)
{
    std::cout << value << " ";
}

// 1. the address of an array
// 2. the length of the array
// 3. a function that will be call on every element of the array
template <typename T>
void iter(T *ptr, int size, void (*func_ptr)(T))
{
    for(int i = 0; i < size; i++)
    {
       (*func_ptr)(*(ptr + i));
    }
}

#endif