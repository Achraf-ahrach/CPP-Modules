#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    for (int i = 5 ; i < 10; i++)
        mstack.push(i);

    MutantStack<int>::iterator Begin = mstack.begin();
    MutantStack<int>::iterator End = mstack.end();

    std::cout << "stack:  {";
    while (Begin != End)
    {
        std::cout << *Begin;
        ++Begin;
        if (Begin != End)
            std::cout << ',';
    }
    std::cout << '}' << std::endl;

    std::cout << "top is: "<< mstack.top() << std::endl;

    std::cout << "size = " << mstack.size() << std::endl;

    std::cout << "pop : " << mstack.top() << std::endl;
    mstack.pop();

    std::cout << "size = " << mstack.size() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "stack:  {";
    while (it != ite)
    {
        std::cout << *it;
        ++it;
        if (it != ite)
            std::cout << ',';
    }
    std::cout << '}'<< std::endl;
    return 0;
}