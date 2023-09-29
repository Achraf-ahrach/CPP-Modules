#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
#define RESET   "\033[0m"
#define RED     "\033[31m"

class Bitcoin
{
    private:
        std::map<std::string, float>    _map;
    public:
        void    read_database();
        void    bitcoin_price(std::ifstream &inputFile);
};
#endif