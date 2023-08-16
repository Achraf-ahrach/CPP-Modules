#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("_A_ ");
    DiamondTrap b("_B_ ");
    std::cout << std::endl;

    a.highFivesGuys();
    a.guardGate();
    a.takeDamage(42);
    b = a;
    b.takeDamage(1337);
    b.beRepaired(2023);
    std::cout << std::endl;

    return 0;
}