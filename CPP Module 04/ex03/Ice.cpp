#include "./header_files/Ice.hpp"

Ice::Ice()
{
    //std::cout << "Ice: Default constructor called" << std::endl;
    type = "ice";
}

Ice::~Ice()
{
    //std::cout << "Ice: Destructor called" << std::endl;
}

Ice& Ice::operator = (const Ice& other)
{
    //std::cout << "Ice: copy assignment operator" << std::endl;
    type = other.type;
    return (*this);
}

Ice::Ice(const Ice& other) : AMateria()
{
    //std::cout << "Ice: copy constructor" << std::endl;
    *this = other;
}

AMateria*   Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName();
    std::cout << " *" << std::endl;
}
