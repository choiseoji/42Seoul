#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
private:
    int arr_size;
    T *arr;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &a);
    Array& operator=(const Array &a);
    ~Array();

    T& operator[](int idx);
    const T& operator[](const int idx) const ;
    int size(void) const ;

    class outOfBound : public std::exception
    {
    public:
		virtual const char* what(void) const throw()
		{
			return ("[error] out of bound");
		}
    };
};

#include "Array.tpp"

#endif
