#include "Span.hpp"

int main()
{
    Span sp = Span(10000);
    std::vector<int>    src;

    for(int i = 0; i < 10000; i++)
        src.push_back(i);

    sp.add_range(src);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}