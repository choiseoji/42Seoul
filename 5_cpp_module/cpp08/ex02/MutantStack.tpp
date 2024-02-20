#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template<typename T>
MutantStack<T>::MutantStack(void) { }

// template<typename T>
// MutantStack<T>::MutantStack(const MutantStack& ms)
// {

// }

// template<typename T>
// MutantStack& MutantStack<T>::operator=(const MutantStack& ms)
// {

// }

template<typename T>
MutantStack<T>::~MutantStack(void) { }

template<typename T>
void MutantStack<T>::push(T value)
{
    st.push_back(value);
}

template<typename T>
void MutantStack<T>::pop(void)
{
    if (st.size() > 0)
        st.pop_back();
}

template<typename T>
T& MutantStack<T>::top(void)
{
    return (st.back());
}

template<typename T>
size_t MutantStack<T>::size(void)
{
    return (st.size());
}

#endif