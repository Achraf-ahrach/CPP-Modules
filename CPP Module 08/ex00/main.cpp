#include "easyfind.hpp"

// https://caiorss.github.io/C-Cpp-Notes/STL%20Iterators%20and%20Algorithms.html

int main()
{
    std::vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    try
    {
        easyfind(arr, 5);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}