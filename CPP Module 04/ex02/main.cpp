#include "Cat.hpp"
#include "Dog.hpp"

void    f(int N)
{
    Animal **a = new Animal*[N];
    int i = 0;
    int j;

    j = 1;
    for(; i < N/2; i++)
    {
        std::cout << "[" << j << "] ";
        a[i] = new Dog();
        j++;
    }
    j = 1;
    for(; i < N ; i++)
    {
        std::cout << "[" << j << "] ";
        a[i] = new Cat();
        j++;
    }
    std::cout << std::endl;

    //* print sounds the animals *//
    for (int i = 0; i < N ; i++)
    {
        a[i]->makeSound();
        delete a[i];
    }
    delete []a;
}

int main()
{
    int N = 10;

    f(N);
    return 0;
}
