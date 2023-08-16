#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedValue;
        static const int fractionalBits = 8;
    public:
            Fixed();                // Default constructor
            Fixed(int intValue);    // Constructor with int parameter
            Fixed(float floatValue); // Constructor with float parameter
            Fixed(const Fixed& other);
            ~Fixed();                     // Destructor

            float toFloat() const;
            static Fixed& min(Fixed& s1, Fixed& s2);
            static Fixed& max(Fixed& s1, Fixed& s2);
            static const Fixed& min(const Fixed& s1, const Fixed& s2);
            static const Fixed& max(const Fixed& s1, const Fixed& s2);

            Fixed&  operator = (const Fixed& other);
            bool    operator == (const Fixed& other) const ;
            bool    operator > (const Fixed& other) const ;
            bool    operator < (const Fixed& other) const ;
            bool    operator <= (const Fixed& other) const ;
            bool    operator >= (const Fixed& other) const ;
            bool    operator != (const Fixed& other) const ;

            Fixed   operator * (const Fixed& other) const ;
            Fixed   operator + (const Fixed& other) const ;
            Fixed   operator / (const Fixed& other) const ;
            Fixed   operator - (const Fixed& other) const ;

            Fixed&  operator++();       // Pre-increment operator
            Fixed   operator++(int);    // Post-increment operator
            Fixed&  operator--();       // Pre-decrement operator
            Fixed   operator--(int);    // post-decrement operator
};

std::ostream& operator << (std::ostream& os, const Fixed& obj);

#endif