#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
#define RESET   "\033[0m"
#define RED     "\033[31m"

void    read_database(std::map<std::string, float> &_map);
void    bitcoin_price(std::map<std::string, float> &_map, std::ifstream &inputFile);

#endif