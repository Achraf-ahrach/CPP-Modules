#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 0, 72, 45)
{
    target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 0, 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator = (other);
    target = other.target;

    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm()
{
    *this = other;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getsigning() == 0 && getgrade_sign() > executor.getGrade())
        throw AForm::GradeTooHighException("RobotomyRequestForm: check that the form is signed and grade of the bureaucrat is very low !");
    else if (getsigning() == 0)
        throw AForm::GradeTooHighException("RobotomyRequestForm: check that the form is signed !");
    else if (getgrade_sign() > executor.getGrade())
        throw AForm::GradeTooHighException("RobotomyRequestForm: grade of the bureaucrat is very low !");
    else
    {
        srand(time(NULL));
        int nb_randome = rand() % 2;
        if (nb_randome == 1)
            throw AForm::GradeTooHighException("RobotomyRequestForm: has been robotomized successfully");
        else
            throw AForm::GradeTooHighException("RobotomyRequestForm: the robotomy failed !");
    }
}
