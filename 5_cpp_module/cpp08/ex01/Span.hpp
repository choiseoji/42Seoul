#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>

class Span
{
private:
    unsigned int N;
    std::vector<int> arr;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &sp);
    Span& operator=(const Span &sp);
    ~Span();

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};

#endif