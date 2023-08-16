#include "Point.hpp"

int main()
{
    Point a(7, 7);
    Point b(11, 1);
    Point c(2, 2);
    Point point(7, 3);

    if (point.bsp(a, b, c, point) == false)
        std::cout << "false" << std::endl;
    else
        std::cout << "true" << std::endl;
}
