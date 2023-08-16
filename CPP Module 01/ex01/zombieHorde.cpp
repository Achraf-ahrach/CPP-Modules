#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    Zombie *harde;

    harde = new Zombie[N];
    for (int i = 0; i < N; i++)
        harde[i].name = name;
    return (harde);
}