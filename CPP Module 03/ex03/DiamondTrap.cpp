#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " has been created!" << std::endl;
    this->name = "[NAME ?]";
    ClapTrap::Name = this->name;
    name = Name;
    Hit_points = FragTrap::Hit_points;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
}

DiamondTrap::DiamondTrap(std::string Name)
{
    std::cout << "DiamondTrap " << Name << " has been created!" << std::endl;
    ClapTrap::Name = Name + "_clap_name";
    name = Name;
    Hit_points = FragTrap::Hit_points;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
}

DiamondTrap&    DiamondTrap::operator = (const DiamondTrap& other)
{
    name = other.name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    *this = other;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "ClapTrap name: " << ClapTrap::Name << " | DiamondTrap name: " << name << std::endl;   
}

DiamondTrap::~DiamondTrap()
{
   std::cout << "DiamondTrap " << Name << " has been destroyed!" << std::endl;
}

void    DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
