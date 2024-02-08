#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>

// container 안에서 find 수 찾기 (container은 vector, deque 이런거..)
template <typename T>
typename T::iterator easyfind(T& container, int find)
{
    typename T::iterator iter = container.begin();
    while (iter != container.end())
    {
        if (*iter == find)
            return (iter);
        iter++;
    }
    throw (std::out_of_range("element not found in the container"));
}

#endif