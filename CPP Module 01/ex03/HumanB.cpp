#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
    this->club = NULL;
    this->str = str;
}

void    HumanB::setWeapon(Weapon &club)
{
    this->club = &club;
}

void    HumanB::attack()
{
    std::cout << str << std::endl;
    if (club)
        std::cout << club->getType() << std::endl;
    else
        std::cout << "HumanB doesn't have a weapon!" << std::endl;
}