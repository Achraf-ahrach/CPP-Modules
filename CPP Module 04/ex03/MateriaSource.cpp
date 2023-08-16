#include "./header_files/MateriaSource.hpp"
#include <string.h>

MateriaSource::MateriaSource()
{
    memset(materias, 0, sizeof(materias));
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

MateriaSource&  MateriaSource::operator = (const MateriaSource& other)
{
    if (this == &other)
        return (*this);
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
        materias[i] = NULL;
        if (other.materias[i]->getType() == "ice")
            materias[i] = new Ice();
        else if (other.materias[i]->getType() == "cure")
            materias[i] = new Cure(); 
    }
    return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    memset(materias, 0, sizeof(materias));
    *this = other;
}

void    MateriaSource::learnMateria(AMateria* _new)
{
    for (int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = _new;
            return ;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    AMateria *new_Materia = NULL;
    for (int i = 0; i < 4 ; i++)
    {
        if (materias[i]->getType() == type)
        {
            new_Materia = materias[i]->clone();
            return (new_Materia);
        }
    }
    return (new_Materia);
}