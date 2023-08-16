#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap1("achraf");
    ClapTrap clapTrap2("ahrach");

    clapTrap1.attack("sokar");
    clapTrap2.takeDamage(3);
    clapTrap1.beRepaired(5);

    return 0;
}