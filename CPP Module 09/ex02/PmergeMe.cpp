#include "PmergeMe.hpp"

int ft_stoi(std::string& str)
{
    int len = 0;
    int i = 0;
    long result;

    for (;str[i]; i++)
    {
        if (i == 0 && str[i] == '-')
            throw std::invalid_argument("is number negative !");
        else if ((i == 0 && str[i] == '+') || (str[i] == '0'))
            ;
        else
            break;
    }
    for(; str[i]; i++)
    {
        if (!isdigit(str[i]))
            throw std::invalid_argument("is not digit !");
        len++;
    }
    result = std::atoi(str.c_str());
    if (len > 10 || result > INT_MAX)
        throw std::out_of_range("Out of Range !");
    return (result);
}

void    split(std::vector<int> &_vector, std::deque<int> &_deque,std::string str, char limiter)
{
    std::string bufer;
    std::stringstream ss(str);

    while (std::getline(ss, bufer, limiter))
    {
        try
        {
            int value = ft_stoi(bufer);
            _vector.push_back(value);
            _deque.push_back(value);
        }
        catch (std::exception &e)
        {
            std::cout << str << ": " << e.what() << std::endl;
            exit (1);
        }
    }
}

std::vector<int>    SortVector(std::vector<int> _vector)
{
    std::vector<int>::iterator it;
    std::vector<int>    last_one;
    std::vector<int>    big_numbers;
    std::vector<int>    numbers_is_sort;
    size_t              index = 0;

    if ((_vector.size() == 1))
        return (_vector);
    for (;index + 1 < _vector.size(); index += 2)
    {
        if (_vector[index] > _vector[index+1])
            std::swap(_vector[index], _vector[index + 1]);
    }
    if (index < _vector.size()) /// keep the last if the number of elements is odd.
    {
        last_one.push_back(_vector[index]);
        _vector.erase(_vector.begin() + index);
    }
    for (index = 0;index < _vector.size(); index++) /// push small numbers to big_numbers
    {
        big_numbers.push_back(_vector[index + 1]);
        _vector.erase(_vector.begin() + index + 1);
    }
    numbers_is_sort = SortVector(big_numbers);

    for (index = 0; index < _vector.size(); index++)
    {
        it = std::upper_bound(numbers_is_sort.begin(), numbers_is_sort.end(), _vector[index]);
        numbers_is_sort.insert(it, _vector[index]);
    }

    if (!last_one.empty())
    {
        it = std::upper_bound(numbers_is_sort.begin(), numbers_is_sort.end(), last_one[0]);
        numbers_is_sort.insert(it, last_one[0]);
    }
    return (numbers_is_sort);
}

std::deque<int>    SortDeque(std::deque<int> _deque)
{
    std::deque<int>::iterator it;
    std::deque<int>    last_one;
    std::deque<int>    big_numbers;
    std::deque<int>    numbers_is_sort;
    size_t              index = 0;

    if ((_deque.size() == 1))
        return (_deque);
    for (;index + 1 < _deque.size(); index += 2)
    {
        if (_deque[index] > _deque[index+1])
            std::swap(_deque[index], _deque[index + 1]);
    }
    if (index < _deque.size()) /// keep the last if the number of elements is odd.
    {
        last_one.push_back(_deque[index]);
        _deque.erase(_deque.begin() + index);
    }
    for (index = 0;index < _deque.size(); index++) /// push small numbers to big_numbers
    {
        big_numbers.push_back(_deque[index + 1]);
        _deque.erase(_deque.begin() + index + 1);
    }
    numbers_is_sort = SortDeque(big_numbers);

    for (index = 0; index < _deque.size(); index++)
    {
        it = std::upper_bound(numbers_is_sort.begin(), numbers_is_sort.end(), _deque[index]);
        numbers_is_sort.insert(it, _deque[index]);
    }

    if (!last_one.empty())
    {
        it = std::upper_bound(numbers_is_sort.begin(), numbers_is_sort.end(), last_one[0]);
        numbers_is_sort.insert(it, last_one[0]);
    }
    return (numbers_is_sort);
}

void    PmergeMe(char **av)
{
    std::vector<int>    _vector;
    std::deque<int>     _deque;
    std::vector<int>    numbers_is_sorted;
    std::vector<int>::iterator it;
    clock_t start, end;
    double  time_vector, time_deque;

    for (int i = 1; av[i]; i++)
        split(_vector, _deque, std::string(av[i]), ' ');
    std::cout << "Before:";
    for (it = _vector.begin();it != _vector.end();it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    start = clock();
    numbers_is_sorted = SortVector(_vector);
    end = clock();
    time_vector = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = clock();
    SortDeque(_deque);
    end = clock();
    time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "after:";
    for (it = numbers_is_sorted.begin();it != numbers_is_sorted.end();it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << time_vector << " s" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(5) << time_deque << " s" << std::endl;
}