#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> _vector;
    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator = (const Span &other);
        void    addNumber(unsigned int number);
        int     shortestSpan() const ;
        int     longestSpan() const ;
};

#endif