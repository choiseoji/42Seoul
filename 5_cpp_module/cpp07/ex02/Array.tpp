#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void)
{
	arr_size = 0;
    arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr_size = n;
    arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array &a)
{
	int s = sizeof(a.arr);
	this->arr = new T[s];
	for(int i = 0; i < s; i++)
	{
		this->arr[i] = a.arr[i];
	}
	arr_size = s;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &a)
{
	if (this != &a)
	{
		delete[] this->arr;

		int s = sizeof(a.arr);
		this->arr = new T[s];
		for(int i = 0; i < s; i++)
		{
			this->arr[i] = a.arr[i];
		}
		arr_size = s;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] arr;
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arr_size)
		throw (outOfBound());
	return (arr[idx]);
}

template <typename T>
const T& Array<T>::operator[](const int idx) const
{
	if (idx < 0 || idx >= arr_size)
		throw (outOfBound());
	return (arr[idx]);
}

template <typename T>
int Array<T>::size(void) const
{
	return (this->arr_size);
}

#endif
