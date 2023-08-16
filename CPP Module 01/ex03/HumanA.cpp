#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &club) : str(str), club(club)
{
    //this->str = str;
    // this->club = club;
}

void    HumanA::attack()
{
    std::cout << str << std::endl;
    std::cout << club.getType() << std::endl;
}