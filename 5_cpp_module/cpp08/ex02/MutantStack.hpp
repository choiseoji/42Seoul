#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <vector>

template<typename T>
class  MutantStack
{
private:
    std::vector<T> st;

public:
    MutantStack();
    MutantStack(const MutantStack& ms);
    MutantStack& operator=(const MutantStack& ms);
    ~MutantStack();

    void push(T value);
    void pop();
    T& top();
    size_t size();

    class iterator
    {

    };
};

# include "MutantStack.tpp"

#endif