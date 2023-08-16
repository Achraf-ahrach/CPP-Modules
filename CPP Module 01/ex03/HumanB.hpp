#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class   HumanB
{
    private:
        std::string str;
        Weapon      *club;
    public:
        HumanB(std::string);
        void    setWeapon(Weapon &club);
        void    attack();
};
#endif
