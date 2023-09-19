#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <deque>

template <class T, class Container = std::deque<T> > // deque by default

class MutantStack : public std::stack<T, Container>
{
    public:
        ~MutantStack(){}
        MutantStack(){}
        MutantStack& operator = (const MutantStack &other)
        {
            if (this == &other)
                return (*this);
            std::stack<T, Container>::operator = (other); 
            return (*this);
        }
        MutantStack(const MutantStack &other) : std::stack<T, Container>(other)
        {
            *this = other;
        }
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        iterator    begin()
        {
            return (this->c.begin());
        }
        iterator    end()
        {
            return (this->c.end());
        }
};

#endif