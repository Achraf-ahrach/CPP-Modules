#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        void    execute(Bureaucrat const & executor) const;
};

#endif