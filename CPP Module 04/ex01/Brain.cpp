#include "Brain.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
        ideas[i] = "idea";
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& other)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "stolen " + other.ideas[i];
    std::cout << "Brain: copy assignment operator" << std::endl;
    return (*this);
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain: copy constructor" << std::endl;
    *this = other;
}

std::string Brain::getIdea(int index) const
{
    std::string idea;
    if (index < 0 || index >= 100)
        return idea;
    idea = ideas[index];
    return (idea);
}

void    Brain::setIdea(std::string idea, int index)
{
    if (index < 0 || index >= 100)
        return ;
    ideas[index] = idea;
}