#include "main.hpp"

std::string replaceOccurrences(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t      start = 0;
    size_t      found = 0;

    while ((found = line.find(s1, start)) != std::string::npos)
    {
        result += line.substr(start, found - start);
        result += s2;
        start = found + s1.length();
    }
    result += line.substr(start);
    return(result);
}

void    replacing(std::string filename, char *s1, char *s2)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cout << strerror(errno) << std::endl;
        return ;
    }
    std::string outputFile = filename + ".replace";
    std::ofstream output(outputFile);
    if (!output.is_open())
    {
        std::cout << strerror(errno) << std::endl;
        inputFile.close();
        return ;
    }
    std::string line;
    std::string replacedLine;
    while (std::getline(inputFile, line))
    {
        replacedLine = replaceOccurrences(line, s1, s2);
        output << replacedLine << std::endl;
    }
    inputFile.close();
    output.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error: that tkaes three parameters !" << std::endl;
        return (1);
    }
    replacing(av[1], av[2], av[3]);
    return (0);
}
