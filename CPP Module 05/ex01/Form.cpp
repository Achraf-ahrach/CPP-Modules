#include "Form.hpp"

Form::Form() : name("default") , grade_sign(150), grade_execute(150)
{
    signing = 0;
}

Form::Form(std::string name, bool signing, const int grade_sign, const int grade_execute) : name(name), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (getgrade_sign() <= 1 || getgrade_execute() <= 1)
        throw Form::GradeTooLowException("Grade Too Low Exception");
    else if (getgrade_sign() > 150 || getgrade_execute() > 150)
        throw Form::GradeTooHighException("Grade Too High Exception");
    else
    {
        this->signing = signing;
    }
}

Form::~Form()
{}

Form &Form::operator = (const Form &other)
{
    if (this == &other)
        return (*this);
    signing = other.signing;

    return (*this);
}

Form::Form(const Form &other) : name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
    *this = other;
}

std::ostream &operator << (std::ostream &out, const Form &c)
{
    out << "name: " << c.getname() << " | signing: " << c.getsigning();
    out << " | grade_sign: " << c.getgrade_sign();
    out << " | grade_execute: " << c.getgrade_execute();
    
    return (out);
}

std::string Form::getname() const
{
    return (name);
}

bool    Form::getsigning() const
{
    return (signing);
}

int Form::getgrade_sign() const
{
    return (grade_sign);
}

int Form::getgrade_execute() const
{
    return (grade_execute);
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getgrade_sign())
        signing = 1;
    else
        throw Form::GradeTooLowException("the grade is too low");
}

/// GradeTooHighException ///

const char *Form::GradeTooHighException::what() const throw()
{
    return (msg_error);
}

Form::GradeTooHighException::GradeTooHighException(const char *mesage)
{
    msg_error = const_cast<char*>(mesage);
}

/// GradeTooLowException //

const char *Form::GradeTooLowException::what() const throw()
{
    return (msg_error);
}

Form::GradeTooLowException::GradeTooLowException(const char *mesage)
{
    msg_error = const_cast<char*>(mesage);
}