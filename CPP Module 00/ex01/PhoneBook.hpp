#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class   PhoneBook
{
    private:
        Contact contact[8];
    public:
        int     search(int i, std::string str);
        void    add(int *i, int *old);
        int     ft_isdigit(const char *str);
        void    print_ten(std::string contact);
};

#endif