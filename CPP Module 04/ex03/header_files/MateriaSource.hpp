#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        AMateria*   materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator = (const MateriaSource &other);
        ~MateriaSource();
        void learnMateria(AMateria *_new);
        AMateria* createMateria(std::string const & type);
};

#endif