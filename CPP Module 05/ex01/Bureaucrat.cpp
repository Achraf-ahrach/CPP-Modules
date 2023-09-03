#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException("Grade Too Low Exception");
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException("Grade Too High Exception");
    else
    {
        this->grade = grade;
    }
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &other)
{
    if (this == &other)
        return (*this);
    grade = other.grade;
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    *this = other;
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void    Bureaucrat::increment_grade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException("Grade Too High Exception");
    else
        grade--;
}

void    Bureaucrat::decrement_grade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException("Grade Too low Exception");
    else
        grade++;
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &c)
{
    out << c.getName();
    out << ", bureaucrat grade ";
    out << c.getGrade();

    return (out);
}

/// GradeTooHighException ///

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (msg_error);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *mesage)
{
    msg_error = const_cast<char*>(mesage);
}

/// GradeTooLowException //

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (msg_error);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *mesage)
{
    msg_error = const_cast<char*>(mesage);
}

void    Bureaucrat::signForm(Form &form)
{
    form.beSigned(*this);
    if (form.getsigning() == 1)
        std::cout << getName() << " signed " << form.getname() << std::endl;
    else
    {
        std::cout << getName() << " couldn’t sign " << form.getname();
        std::cout << " because the grade is too low" << std::endl;
    }
}
