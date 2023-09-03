#include "main.hpp"

Base::~Base()
{}

A::~A()
{}

B::~B()
{}

C::~C()
{}

Base*   generate(void)
{
    std::srand(std::time(0));
    int randome = std::rand() % 3;

    if (randome == 0)
    {
        A *a = new A();
        return (a);
    }
    else if (randome == 1)
    {
        B *b = new B();
        return (b);
    }
    else if (randome == 2)
    {
        C *c = new C();
        return (c);
    }
    return (NULL);
}

void    identify(Base* p)
{
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);
    if (a)
        std::cout << "Pointer: type of the object pointed to by p is: class A\n";
    else if (b)
        std::cout << "Pointer: type of the object pointed to by p is: class B\n";
    else if (c)
        std::cout << "Pointer: type of the object pointed to by p is: class c\n";
}

void    identify(Base& p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Reference: type of the object pointed to by p is: class A\n";
        (void)a; 
    } catch (...) { }
    
    try {
        B  &b = dynamic_cast<B&>(p);
        std::cout << "Reference: type of the object pointed to by p is: class B\n";
        (void)b;
        
    } catch (...) { }
    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Reference: type of the object pointed to by p is: class c\n"; 
        (void)c;
        
    } catch (...) { }
}

int main()
{
    Base *B = generate();
    identify(B);
    identify(*B);
    delete B;
}