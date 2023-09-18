#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>

void    easyfind(T &container, int integer)
{
    if (std::find(container.begin(), container.end(), integer) == container.end())
    {
        std::cout << integer << ": ";
        throw std::runtime_error("not found !");
    }
    return ;
}

#endif