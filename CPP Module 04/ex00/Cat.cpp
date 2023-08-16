#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other)
{
    std::cout << "Cat: copy assignment operator" << std::endl;
    type = other.type;
    return (*this);
}

Cat::Cat(const Cat& other) : Animal()
{
    std::cout << "Cat: copy constructor" << std::endl;
    *this = other;
}

void Cat::makeSound() const
{
    std::cout << "Cat: the cat sound!" << std::endl;
}