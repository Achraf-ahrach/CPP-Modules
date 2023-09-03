#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

class RobotomyRequestForm : public AForm 
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator = (const RobotomyRequestForm &other);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        void    execute(Bureaucrat const & executor) const;
};

#endif