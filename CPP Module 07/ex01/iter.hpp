#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstring>

template <typename T>

void    function(T *element)
{
    std::cout << *element;
}

template <typename T>

void    iter(T *A, int length, void (*f)(T *element))
{
    for(int i = 0;i < length; i++)
        f(&A[i]);
}

#endif
