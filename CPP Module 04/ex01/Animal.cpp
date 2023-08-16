#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& other)
{
    std::cout << "Animal: copy assignment operator" << std::endl;
    type = other.type;
    return (*this);
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal: copy constructor" << std::endl;
    *this = other;
}

void    Animal::makeSound() const
{
    std::cout << "Animal: Animal sound" << std::endl;
}

std::string Animal::gettype() const
{
    return (type);
}
