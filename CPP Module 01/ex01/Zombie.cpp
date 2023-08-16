#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
    std::cout << "zombie " << name << ": destroyed !" << std::endl;
}

void    Zombie::announce()
{
    std::cout << "I am zombie :" << name << "!" << std::endl;
}
