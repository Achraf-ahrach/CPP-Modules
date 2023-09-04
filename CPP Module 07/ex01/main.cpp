#include "iter.hpp"

int main()
{
    int length = 7;
    char array[length];

    std::strncpy(array, "Achraf", length);
    iter(array, length-1, function<char>);
    std::cout << std::endl;

    int array_int[] = {1,2,3,4,5,6};
    iter(array_int, length-1, function<int>);
    std::cout << std::endl;
}
