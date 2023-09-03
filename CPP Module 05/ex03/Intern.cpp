#include "Intern.hpp"

Intern::Intern()
{}

Intern& Intern::operator = (const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern::~Intern()
{}

AForm*  Intern::makeForm(std::string str, std::string target)
{
    std::string s[3] = {"Presidential pardon", "robotomy request", "Shrubbery creation"};
    int i;

    for(i = 0; i < 3 && (s[i] != str);)
        i++;
    switch (i)
    {
        case 0:
        {
            PresidentialPardonForm *P = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << P->getname() << std::endl;
            return (P);
        }
        case 1:
        {
            RobotomyRequestForm *R = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << R->getname() << std::endl;
            return (R);
        }
        case 2:
        {
            ShrubberyCreationForm *S = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << S->getname() << std::endl;
            return (S);
        }
        default:
        {
            std::cout << "Intern uncreates !" << std::endl;
            return (NULL);
        }
    }
}
