#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
private:
    int size;   // size에 대한 정보를 가지고 있어야 함!!
    T *arr;

public:
    Array()   // 빈 arr 만들기
    {
        size = 0;
        arr = new T();
    }
    Array(unsigned int n) // 크기가 n인 arr 만들기
    {
        size = n;
        arr = new T[n];
    }
    Array(const Array &a)  // 깊은 복사
    {
        int s = sizeof(a.arr);
        this->arr = new T[s];
        for(int i = 0; i < s; i++)
        {
            this->arr[i] = a.arr[i];
        }
        size = s;
    }
    Array& operator=(const Array &a)  // 깊은 복사
    {
        if (this != &a)
        {
            // 복사하기 전에 값이 있는지 확인하고 delete 먼저 해주기
            int s = sizeof(a.arr);
            this->arr = new T[s];
            for(int i = 0; i < s; i++)
            {
                this->arr[i] = a.arr[i];
            }
            size = s;
        }
        return (*this);
    }
    ~Array()
    {
        for(int i = 0; i < size; i++)
        {
            delete arr[i];
        }
        delete arr;
    }

    T operator[](int idx)
    {
        if (idx < 0 || idx > size)
            throw (outOfBound());
        return (arr[idx]);
    }

    int size(void) const
    {
        return (this->size);
    }

    class outOfBound : public std::exception
    {

    };
};

#endif
