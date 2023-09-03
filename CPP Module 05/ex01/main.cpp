#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("A", 100);
        A.increment_grade();
        Form form("Form", 0, 102, 150);
        A.signForm(form);
        std::cout << A << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat B("B", 110);
        B.decrement_grade();
        Form form("Form", 0, 115, 150);
        B.signForm(form);
        std::cout << B << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}