#include "PhoneBook.hpp"

int Contact::GetIndex(void) const
{
    return (this->index);
}

std::string Contact::GetFname(void) const
{
    return (this->fname);
}

std::string Contact::GetLname(void) const
{
    return (this->lname);
}

std::string Contact::GetNickname(void) const
{
    return (this->nickname);
}

std::string Contact::GetPhone_nb(void) const
{
    return (this->phone_nb);
}

void    Contact::SetIndex(int index)
{
    this->index = index;
}
void    Contact::SetFname(std::string str)
{
    this->fname = str;
}
void    Contact::SetLname(std::string str)
{
    this->lname = str;
}

void    Contact::SetNickname(std::string str)
{
    this->nickname = str;
}

void    Contact::SetPhone_nb(std::string str)
{
    this->phone_nb = str;
}