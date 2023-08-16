#ifndef CLAPTRAQ_HPP
#define CLAPTRAQ_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string Name;
        int         Hit_points;
        int         Energy_points;
        int         Attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator = (const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
