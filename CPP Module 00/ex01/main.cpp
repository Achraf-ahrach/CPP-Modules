#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    std::string str;
    int         i;
    int         old;
    PhoneBook   _PhoneBook;

    (void)av;
    if (ac > 1)
    {
        std::cout << "Error: argument one !" << std::endl;
        return (0);
    }
    i = 0;
    old = 0;
    while (1)
    {
        std::cout << "PhoneBook: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            return (0);
        if (!std::strcmp(str.c_str(), "ADD"))
            _PhoneBook.add(&i, &old);
        else if (!std::strcmp(str.c_str(), "SEARCH"))
        {
            if (!i)                                                                                                                                                       
            {
                std::cout << "there is no contact !" << std::endl;
                continue;
            }
            if (_PhoneBook.search(i, str))
                continue;
        }
        else if (!std::strcmp(str.c_str(), "EXIT"))
            exit(1);
        else
            std::cout << "Only ADD or SEARCH or EXIT is allowed" << std::endl;
    }
}