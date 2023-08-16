#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
		Dog(const Dog& newDog);
		Dog& operator=(const Dog& newDog);
		~Dog();
		void makeSound() const;
};

#endif