#include "Span.hpp"

// https://caiorss.github.io/C-Cpp-Notes/STL%20Iterators%20and%20Algorithms.html

int main()
{
    Span sp = Span(5);

    for(int i = 0; i < 10000; i++)
    {
        try
        {
            sp.addNumber(i);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    try
    {
        sp.addNumber(5);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}