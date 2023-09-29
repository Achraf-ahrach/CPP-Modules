#include "BitcoinExchange.hpp"

int no_valid_second(std::string &str)
{
    int cont = 0;

    if (str.empty())
    {
        std::cerr << RED "Error: bad input => value is empty " << RESET << std::endl;
        return (0);
    }
    for (int i = 0;str[i];i++)
    {
        if (i != 0 && str[i] == '.')
            cont++;
        if (str[0] == '-')
        {
            std::cerr << RED "Error: not a positive number." << RESET << std::endl;
            return (0);
        }
        else if (!std::isdigit(str[i]))
        {
            std::cerr << RED "Error: bad input => " << str << RESET << std::endl;
            return (0);
        }
    }
    if (cont > 1)
    {
        std::cerr << RED "Error: bad input => " << str << RESET << std::endl;
        return (0);
    }
    else if (atof(str.c_str()) < 0)
    {
        std::cerr << RED "Error: too small a number." << RESET << std::endl;
        return (0);
    }
    else if (atof(str.c_str()) > 1000)
    {
        std::cerr << RED "Error: too large a number." << RESET << std::endl;
        return (0);
    }
    return (1);
}

int no_valid_first(std::string &str)
{
    int i = -1;
    std::string month;
    std::string day;

    while (str[++i] && str[i] != '-') // years
    {
        if (!std::isdigit(str[i]) || i > 3)
        {
            std::cerr << RED "Error: the date year is not valid !" << RESET << std::endl;
            return (0);
        }
    }
    while (str[++i] && str[i] != '-') // month
    {
        month.push_back(str[i]);
        if ((!std::isdigit(str[i]) || i > 6) || (i == 6 && (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1)))
        {
            std::cerr << RED "Error: the date month is not valid !" << RESET << std::endl;
            return (0);
        }
    }
    while (str[++i]) // day
    {
        day.push_back(str[i]);
        if ((!std::isdigit(str[i]) || i > 9) || (i == 9 && (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1)))
        {
            std::cerr << RED "Error: the date day is not valid !" << RESET << std::endl;
            return (0);
        }
    }
    return (1);
}

void    Bitcoin::read_database()
{
    std::string bufer;
    std::ifstream inputFile_database("data.csv");

    if (!inputFile_database)
    {
        std::cerr << RED "Error: could not open file database !" << RESET << std::endl;
        exit (1);
    }
    std::getline(inputFile_database, bufer);
    while(std::getline(inputFile_database, bufer))
    {
        size_t i = bufer.find(",");
        _map[bufer.substr(0,i)] = atof(bufer.substr(i+1).c_str());
    }
}

void    Bitcoin::bitcoin_price(std::ifstream &inputFile)
{
    std::string bufer;

    std::getline(inputFile, bufer);
    if (bufer != "date | value")
    {
        std::cerr << RED "Error: in format \"date | value\" !" << RESET << std::endl;
        exit (1);
    }
    while(std::getline(inputFile, bufer))
    {
        size_t i = bufer.find(" | ");

        if (i != std::string::npos)
        {
            std::map<std::string, float>::iterator it = _map.lower_bound(bufer.substr(0, i));
            if (it->first != bufer.substr(0, i))
                it--;
            if (bufer.substr(0, i).size() != 10)
                std::cerr << RED "Error: the date is not valid => " << bufer.substr(0, i) << RESET << std::endl;
            else if (bufer.substr(0, i) < _map.begin()->first)
                std::cerr << RED "Error: the date is very smaller => " << bufer.substr(0, i) << RESET << std::endl;
            else
            {
                std::string str_first = bufer.substr(0, i);
                std::string str_second = bufer.substr(i+3);

                if (!no_valid_first(str_first))
                    continue;
                if (!no_valid_second(str_second))
                    continue;
                std::cout << str_first << " => " << str_second << " = ";
                std::cout << (it->second * atof(str_second.c_str())) << std::endl;
            }
        }
        else
            std::cerr << RED "Error: bad input => " << bufer << RESET << std::endl;
    }
}