#include "RPN.hpp"

int ft_operator(int a, int b, char x)
{
    if (x == '+')
        return (a + b);
    else if (x == '-')
        return (a - b);
    else if (x == '*')
        return (a * b);
    else if (x == '/')
    {
        if (b == 0)
        {
            std::cout << "Error: Attempt to divide by zero" << std::endl;
            exit (1);
        }
        return (a / b);
    }
    return (0);
}

void    Reverse_Polish_Notation(char *str)
{
    std::stack<int> _stack;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
            continue;
        else if (i != 0 && !str[i + 1] && str[i + 1] != ' ' && str[i - 1] != ' ')
        {
            std::cout << "Error:" << std::endl;
            return ;
        }
        if (std::isdigit(str[i]))
        {
            _stack.push(str[i] - 48);
        }
        else if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && (str[i + 1] == ' ' || !str[i + 1]))
        {
            int top_1;
            int top_2;

            if (_stack.empty())
            {
                std::cout << "Error:" << std::endl;
                return ;
            }
            else
            {
                top_1 = _stack.top();
                _stack.pop();
            }
            if (_stack.empty())
            {
                std::cout << "Error:" << std::endl;
                return ;
            }
            else
            {
                top_2 = _stack.top();
                _stack.pop();
                _stack.push(ft_operator(top_2, top_1, str[i]));
            }
        }
        else
        {
            std::cout << "Error:" << std::endl;
            return ;
        }
    }
    if (_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else
        std::cout << "Error:" << std::endl;
}