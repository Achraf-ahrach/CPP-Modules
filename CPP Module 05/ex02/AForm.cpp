#include "AForm.hpp"

AForm::AForm() : name("default") , grade_sign(150), grade_execute(150)
{
    signing = 0;
}

AForm::AForm(std::string name, bool signing, const int grade_sign, const int grade_execute) : name(name), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (getgrade_sign() <= 1 || getgrade_execute() <= 1)
        throw AForm::GradeTooLowException("Grade Too Low Exception");
    else if (getgrade_sign() > 150 || getgrade_execute() > 150)
        throw AForm::GradeTooHighException("Grade Too High Exception");
    else
    {
        this->signing = signing;
    }
}

AForm::~AForm()
{}

AForm &AForm::operator = (const AForm &other)
{
    if (this == &other)
        return (*this);
    signing = other.signing;

    return (*this);
}

AForm::AForm(const AForm &other) : name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
    *this = other;
}

std::ostream &operator << (std::ostream &out, const AForm &c)
{
    out << "name: " << c.getname() << " | signing: " << c.getsigning();
    out << " | grade_sign: " << c.getgrade_sign();
    out << " | grade_execute: " << c.getgrade_execute();
    
    return (out);
}

std::string AForm::getname() const
{
    return (name);
}

bool    AForm::getsigning() const
{
    return (signing);
}

int AForm::getgrade_sign() const
{
    return (grade_sign);
}

int AForm::getgrade_execute() const
{
    return (grade_execute);
}

void    AForm::setsigning(bool signing)
{
    this->signing = signing;
}

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getgrade_sign())
        signing = 1;
    else
        throw AForm::GradeTooLowException("the grade is too low");
}

/// GradeTooHighException ///

const char *AForm::GradeTooHighException::what() const throw()
{
    return (msg_error);
}

AForm::GradeTooHighException::GradeTooHighException(const char *mesage)
{
    msg_error = const_cast<char*>(mesage);
}

/// GradeTooLowException //

const char *AForm::GradeTooLowException::what() const throw()
{
    return (msg_error);
}

AForm::GradeTooLowException::GradeTooLowException(const char *mesage)
{
    msg_error = const_cast<char*>(mesage);
}