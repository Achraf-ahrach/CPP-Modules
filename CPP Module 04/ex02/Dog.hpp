#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	protected:
		Brain*	brain;
    public:
        Dog();
		Dog(const Dog& newDog);
		Dog& operator=(const Dog& newDog);
		~Dog();
		void makeSound() const;
};

#endif