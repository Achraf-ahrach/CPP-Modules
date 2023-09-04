#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstring>

template <typename T>

void    function(T element)
{
    std::cout << element;
}

template <typename T, typename F>

void    iter(T *A, int length, F function)
{
    for(int i = 0;i < length; i++)
        function(A[i]);
}

#endif
