#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other)
{
    std::cout << "Dog: copy assignment operator" << std::endl;
    type = other.type;
    return (*this);
}

Dog::Dog(const Dog& other) : Animal()
{
    std::cout << "Dog: copy constructor" << std::endl;
    *this = other;
}

void Dog::makeSound() const
{
    std::cout << "Dog: the Dog sound!" << std::endl;
}