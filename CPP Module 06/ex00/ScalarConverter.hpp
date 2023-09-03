#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

class ScalarConverter
{
    private:
        static int     _int;
        static float   _float;
        static char    _char;
        static double  _double;
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter & operator = (const ScalarConverter &other);
        static bool    isfloat(char* charPtr); // static t9der tosel lfunction bla matkriyi obg, and maymknch towsel lchi variabl li machi static !
        static bool    isint(char* charPtr);
        static bool    isdouble(char* charPtr);
        static int     Determine_the_type(char *str);
    public:
        static void    convert(char *av);
};
#endif