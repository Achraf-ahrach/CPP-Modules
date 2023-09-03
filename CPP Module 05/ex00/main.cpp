#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("achraf", 100);
        A.increment_grade();
        std::cout << A << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat B("ahrach", 100);
        B.decrement_grade();
        std::cout << B << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}