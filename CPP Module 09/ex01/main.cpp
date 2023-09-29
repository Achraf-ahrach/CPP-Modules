#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " <...>" << std::endl;
        return (0);
    }
    Reverse_Polish_Notation(av[1]);
}