#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class   HumanA
{
    private:
        std::string str;
        Weapon      &club;
    public:
        HumanA(std::string str, Weapon &club);
        void    attack();
};

#endif