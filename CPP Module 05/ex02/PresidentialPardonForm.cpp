#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 0, 25, 5)
{
    target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 0, 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator = (other);
    target = other.target;

    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm()
{
    *this = other;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getsigning() == 0 && getgrade_sign() > executor.getGrade())
        throw AForm::GradeTooHighException("PresidentialPardonForm: check that the form is signed and grade of the bureaucrat is very low !");
    else if (getsigning() == 0)
        throw AForm::GradeTooHighException("PresidentialPardonForm: check that the form is signed !");
    else if (getgrade_sign() > executor.getGrade())
        throw AForm::GradeTooHighException("PresidentialPardonForm: grade of the bureaucrat is very low !");
    else
    {
        std::cout << "PresidentialPardonForm: has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}
