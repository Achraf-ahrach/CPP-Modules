#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstring>
#include <string>

class   Contact
{
    private:
        int         index;
        std::string fname;
        std::string lname;
        std::string nickname;
        std::string phone_nb;
    public:
        int         GetIndex(void) const;
        std::string GetFname(void) const;
        std::string GetLname(void) const;
        std::string GetNickname(void) const;
        std::string GetPhone_nb(void) const;
        void        SetIndex(int index);
        void        SetFname(std::string str);
        void        SetLname(std::string str);
        void        SetNickname(std::string str);
        void        SetPhone_nb(std::string str);
};

#endif