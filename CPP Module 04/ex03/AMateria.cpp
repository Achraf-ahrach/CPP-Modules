#include "./header_files/AMateria.hpp"

AMateria::AMateria()
{
    //std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
    //std::cout << "AMateria: Destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria& AMateria::operator = (const AMateria& other)
{
    //std::cout << "AMateria: copy assignment operator" << std::endl;
    this->type = other.type;
    return (*this);
}

AMateria::AMateria(const AMateria& other)
{
    //std::cout << "AMateria: copy constructor" << std::endl;
    *this = other;
}

std::string const & AMateria::getType() const
{
    return (type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "* shoots " << target.getName() << " *"<< std::endl;
}
