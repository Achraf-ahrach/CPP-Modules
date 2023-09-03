#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator = (const PresidentialPardonForm &other);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        void    execute(Bureaucrat const & executor) const;
};

#endif