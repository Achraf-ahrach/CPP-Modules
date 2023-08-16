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
          Fixed();                      // Default constructor
          Fixed(const int intValue);    // Constructor with int parameter
          Fixed(const float floatValue); // Constructor with float parameter
          Fixed(const Fixed& other);    // Copy constructor
          ~Fixed();                     // Destructor

          Fixed& operator = (const Fixed& other); // Copy assignment operator
          float toFloat() const; // Convert to float

          int toInt() const;     // Convert to int
};

// Overload << operator for insertion into output stream
std::ostream& operator << (std::ostream& os, const Fixed& fixed);

#endif