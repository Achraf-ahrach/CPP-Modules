#include "Zombie.hpp"

int main()
{
    Zombie *harde;
    int     N;

    harde = NULL;
    N = 4;
    harde = harde->zombieHorde(N, "achraf");
    for (int i = 0; i < N; i++)
        harde->announce();
    delete[] harde;
}