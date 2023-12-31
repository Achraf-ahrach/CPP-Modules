#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED "Usage: " << av[0] << " <input_file>" RESET << std::endl;
        return (0);
    }
    std::ifstream inputFile(av[1]);
    if (!inputFile)
    {
        std::cerr << RED "Error: could not open file <" << av[1] << ">" RESET << std::endl;
        return (0);
    }
    std::map<std::string, float>    _map;
    read_database(_map);
    bitcoin_price(_map, inputFile);
}