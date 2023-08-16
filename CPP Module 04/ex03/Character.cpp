#include "./header_files/Character.hpp"
#include <string.h>
Character::Character()
{
    //std::cout << "Character: Default constructor called" << std::endl;
    memset(materias, 0, sizeof(materias));
}

Character::Character(const std::string name)
{
    //std::cout << "Character: parameters constructor called" << std::endl;
    this->name = name;
    memset(materias, 0, sizeof(materias));
}

Character::~Character()
{
    //std::cout << "Character: Destructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

Character& Character::operator = (const Character& other)
{
    //std::cout << "Character: copy assignment operator" << std::endl;
    if (this == &other)
        return (*this);
    name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete (materias[i]);
        materias[i] = NULL;
        if (materias[i] && other.materias[i]->getType() == "ice")
            materias[i] = new Ice();
        else if (materias[i] && other.materias[i]->getType() == "cure")
            materias[i] = new Cure();
    }
    return (*this);
}

Character::Character(const Character& other)
{
    //std::cout << "Character: copy constructor" << std::endl;
    *this = other;
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && materias[idx])
        materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && materias[idx])
        materias[idx]->use(target);
}