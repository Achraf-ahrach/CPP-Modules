#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: " << av[0] << " <...>" << std::endl;
        return (0);
    }
    PmergeMe(av);
}
