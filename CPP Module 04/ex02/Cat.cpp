#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
}

Cat& Cat::operator = (const Cat& other)
{
    std::cout << "Cat: copy assignment operator" << std::endl;
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

Cat::Cat(const Cat& other) : Animal()
{
    std::cout << "Cat: copy constructor" << std::endl;
    brain = NULL;
    *this = other;
}

void Cat::makeSound() const
{
    std::cout << "Cat: the cat sound!" << std::endl;
}