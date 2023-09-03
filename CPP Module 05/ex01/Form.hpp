#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   name;
        bool                signing;
        const int           grade_sign;
        const int           grade_execute;

    public:
        Form();
        ~Form();
        Form &operator = (const Form &other);
        Form(const Form &other);
        Form(Form &form);
        Form(std::string name, bool signing, const int grade_sign, const int grade_execute);
        void        beSigned(Bureaucrat &form);
        std::string getname() const;
        int         getgrade_sign() const;
        int         getgrade_execute() const;
        bool        getsigning() const;
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

std::ostream &operator << (std::ostream &out, const Form &c);
#endif