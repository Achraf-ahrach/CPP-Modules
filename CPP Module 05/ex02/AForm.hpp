#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string   name;
        bool                signing;
        const int           grade_sign;
        const int           grade_execute;
    public:
        AForm();
        ~AForm();
        AForm &operator = (const AForm &other);
        AForm(const AForm &other);
        AForm(AForm &Aform);
        AForm(std::string name, bool signing, const int grade_sign, const int grade_execute);
        void         beSigned(Bureaucrat &Aform);
        std::string  getname() const;
        int          getgrade_sign() const;
        int          getgrade_execute() const;
        bool         getsigning() const;
        void         setsigning(bool signing);
        virtual void execute(Bureaucrat const & executor) const = 0;
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

std::ostream &operator << (std::ostream &out, const AForm &c);
#endif