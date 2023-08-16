#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string Name)
{
    this->Name = Name;
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
    Name = other.Name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    *this = other;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	--Energy_points;
	std::cout << "ScavTrap " << Name << " attacks " << target
            << ", causing " << Attack_damage << " points of damage!" << std::endl;
}