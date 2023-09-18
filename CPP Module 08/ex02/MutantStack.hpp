#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <class T>

class MutantStack : public std::stack<T>
{
    public:
        ~MutantStack(){}
        MutantStack(){}
        MutantStack& operator = (MutantStack &other)
        {
            if (this == &other)
                return (*this);
            std::stack<T>::operator = (other); 
            return (*this);
        }
        MutantStack(MutantStack &other) : std::stack<T>(other)
        {
            *this = other;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
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