#include "./header_files/Cure.hpp"

Cure::Cure()
{
    //std::cout << "Cure: Default constructor called" << std::endl;
    type = "cure";
}

Cure::~Cure()
{
    //std::cout << "Cure: Destructor called" << std::endl;
}

Cure& Cure::operator = (const Cure& other)
{
    //std::cout << "Cure: copy assignment operator" << std::endl;
    type = other.type;
    return (*this);
}

Cure::Cure(const Cure& other) : AMateria()
{
   // std::cout << "Cure: copy constructor" << std::endl;
    *this = other;
}

AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName();
    std::cout << "’s wounds *" << std::endl;
}
