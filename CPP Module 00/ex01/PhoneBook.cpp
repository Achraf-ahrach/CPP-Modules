#include "PhoneBook.hpp"

int PhoneBook::ft_isdigit(const char *str)
{
    int i = -1;
    while (str[++i])
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

void    PhoneBook::print_ten(std::string contact)
{
    int length;
    int i;

    i = 0;
    length = contact.length();
    while(i < 9 && length)
    {
        std::cout << contact[i++];
        length--;
        if (i == 9)
            std::cout << ".";
    }
}

int  PhoneBook::search(int i, std::string str)
{
    int index;

    for(int j = 0; j < i; j++)
    {
        std::cout << "index: " << contact[j].GetIndex() + 1;
        std::cout << " | first name: ";
        print_ten(contact[j].GetFname());
        std::cout << " | last name: ";
        print_ten(contact[j].GetLname());
        std::cout << " | nickname: ";
        print_ten(contact[j].GetNickname());
        std::cout << std::endl;
    }
    std::cout << "display a specific contact? : ";
    std::getline(std::cin, str);
    if (std::cin.eof())
        exit (1);
    index = atoi(str.c_str());
    if (index < 1 || index > i)
    {
        std::cout << "there is no such index !" << std::endl;
        return (1);
    }
    for(int j = 0;j < i; j++)
    {
        if (index - 1 == contact[j].GetIndex())
        {
            std::cout << "index: " << contact[j].GetIndex() + 1 << std::endl;
            std::cout << "first name: " << contact[j].GetFname() << std::endl;
            std::cout << "last name: " << contact[j].GetLname() << std::endl;
            std::cout << "nickname: " << contact[j].GetNickname() << std::endl;
            std::cout << "phone number: " << contact[j].GetPhone_nb() << std::endl;
        }
    }
    return (0);
}

void    PhoneBook::add(int *i, int *old)
{
    int         j = 1;
    std::string str;
    if (*i == 8)
    {
        std::cout << "first name: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*old].SetFname(str);
        std::cout << "last name: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*old].SetLname(str);
        std::cout << "nickname: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*old].SetNickname(str);
        std::cout << "phone number: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*old].SetPhone_nb(str);
        *old += 1;
        if (*old == 8)
            *old = 0;
    }
    else
    {
        contact[*i].SetIndex(*i);
        std::cout << "first name: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*i].SetFname(str); 
        std::cout << "last name: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*i].SetLname(str);
        std::cout << "nickname: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit (1);
        contact[*i].SetNickname(str);
        while (j)
        {
            std::cout << "phone number: ";
            std::getline(std::cin, str);
            if (std::cin.eof())
                exit (1);
            contact[*i].SetPhone_nb(str);
            if (!ft_isdigit(str.c_str()) || !std::strlen(str.c_str()))
                std::cout << "Error: phone number must be number !" << std::endl;
            else
                j = 0;
        }
        *i += 1;
    }
}
