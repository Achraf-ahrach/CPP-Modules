#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator = (const Dog& other)
{
    std::cout << "Dog: copy assignment operator" << std::endl;
    if (this == &other)
        return (*this);
    type = other.type;
    if (brain)
        delete brain;
    brain = new Brain();
    for(int i = 0; i < 100; i++)
        brain->setIdea(other.brain->getIdea(i), i);
    return (*this);
}

Dog::Dog(const Dog& other) : Animal()
{
    std::cout << "Dog: copy constructor" << std::endl;
    brain = NULL;
    *this = other;
}

void Dog::makeSound() const
{
    std::cout << "Dog: the Dog sound!" << std::endl;
}