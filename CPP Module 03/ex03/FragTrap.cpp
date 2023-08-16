#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap " << Name << " has been created!" << std::endl;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
}

FragTrap::FragTrap(std::string Name)
{
    std::cout << "FragTrap " << Name << " has been created!" << std::endl;
    this->Name = Name;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
    Name = other.Name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

FragTrap::FragTrap(const FragTrap& other)
{
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << ", causing " << Attack_damage << " points of damage!" << std::endl;
}