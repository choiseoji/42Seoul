#include "Span.hpp"

Span::Span(void) { }

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::Span(const Span &sp)
{
    this->N = sp.N;
    this->arr = sp.arr;
}

Span& Span::operator=(const Span &sp)
{
    if (this != &sp)
    {
        this->N = sp.N;
        this->arr = sp.arr;
    }
    return (*this);
}

Span::~Span() { }

void Span::addNumber(int num)
{
    if (arr.size() == N)
        ;// throw ;
    arr.push_back(num);
}

int Span::shortestSpan(void)
{
    if (arr.size() == 0 || arr.size() == 1)
        ;// throw ;
    
    int shortest_span;
    std::vector<int> tmp;

    tmp = arr;
    sort(tmp.begin(), tmp.end());
    shortest_span = tmp[1] - tmp[0];
    for(size_t i = 1; i < tmp.size() - 1; i++)
    {
        if (shortest_span > tmp[i + 1] - tmp[i])
            shortest_span = tmp[i + 1] - tmp[i];
    }
    return (shortest_span);
}

int Span::longestSpan(void)
{
    if (arr.size() == 0 || arr.size() == 1)
        ;// throw ;
    
    std::vector<int> tmp;

    tmp = arr;
    sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}
