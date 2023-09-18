#include "Span.hpp"

Span::Span() : N(0)
{}

Span::~Span()
{}

Span::Span(unsigned int N) : N(N)
{}

Span &Span::operator = (const Span &other)
{
    if (this == &other)
        return (*this);
    if(!_vector.empty())
        _vector.clear();
    N = other.N;
    for (size_t i = 0; i < other._vector.size(); i++)
        this->_vector.push_back(other._vector[i]);
    return (*this);
}

Span::Span(const Span &other)
{
    *this = other;
}

void    Span::addNumber(unsigned int number)
{
    if(_vector.size() <= N)
        _vector.push_back(number);
    else
        throw std::runtime_error("addNumber: there are already N elements stored");
}

int Span::shortestSpan() const
{
    if (_vector.empty())
        throw std::runtime_error("shortestSpan: there are no numbers stored");
    else if (_vector.size() == 1)
        throw std::runtime_error("shortestSpan: only one");
    std::vector<int> tmp = _vector;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (size_t i = 0 ; i+1 < tmp.size(); i++)
    {
        if (tmp[i+1] - tmp[i] < min)
            min = tmp[i+1] - tmp[i];
    }
    return (min);
}

int Span::longestSpan() const
{
    if (_vector.empty())
        throw std::runtime_error("shortestSpan: there are no numbers stored");
    else if (_vector.size() == 1)
        throw std::runtime_error("shortestSpan: only one");
    std::vector<int> tmp = _vector;
    std::sort(tmp.begin(), tmp.end());
    return (*(tmp.end()-1) - *tmp.begin());
}

void Span::add_range(std::vector<int> &src)
{
    if (_vector.size() + src.size() <= N)
        _vector.insert(_vector.end(), src.begin(), src.end());
    else
        throw std::runtime_error("add_range: there are already N elements stored");
}