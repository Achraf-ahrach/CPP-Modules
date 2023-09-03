#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern& operator = (const Intern &other);
        Intern(const Intern &other);
        ~Intern();
        AForm*  makeForm(std::string str1, std::string str2);
};

#endif