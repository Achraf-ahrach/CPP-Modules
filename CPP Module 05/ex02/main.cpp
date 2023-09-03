#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat B("A", 150);
        PresidentialPardonForm P("P");
        P.setsigning(1);
        B.executeForm(P);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat B("A", 150);
        RobotomyRequestForm R("R");
        R.setsigning(1);
        B.executeForm(R);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat B("A", 150);
        ShrubberyCreationForm S("S");
        S.setsigning(1);
        B.executeForm(S);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}