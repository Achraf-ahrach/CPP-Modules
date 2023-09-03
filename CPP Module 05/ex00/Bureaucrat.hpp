#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat& operator = (const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void    increment_grade();
        void    decrement_grade();
        class GradeTooHighException : public std::exception
        {
            private:
                const char *msg_error;
            public:
                const char* what() const throw();
                GradeTooHighException(const char *mesage);
        };
        class GradeTooLowException : public std::exception
        {
            private:
                const char *msg_error;
            public:
                const char* what() const throw();
                GradeTooLowException(const char *mesage);
        };
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &c);

#endif