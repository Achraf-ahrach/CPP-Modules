#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {}

Fixed::Fixed(const int intValue) : fixedValue(intValue << fractionalBits) {}

Fixed::Fixed(const float floatValue) : fixedValue(roundf(floatValue * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : fixedValue(other.fixedValue) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator = (const Fixed& other)
{
    fixedValue = other.fixedValue;
    return *this;
}

bool Fixed::operator > (const Fixed& other) const
{
    return fixedValue > other.fixedValue;
}

bool Fixed::operator < (const Fixed& other) const
{
    return fixedValue < other.fixedValue;
}

bool Fixed::operator >= (const Fixed& other) const
{
    return fixedValue >= other.fixedValue;
}

bool Fixed::operator <= (const Fixed& other) const
{
    return fixedValue <= other.fixedValue;
}

bool Fixed::operator == (const Fixed& other) const
{
    return fixedValue == other.fixedValue;
}

bool Fixed::operator != (const Fixed& other) const
{
    return fixedValue != other.fixedValue;
}

Fixed Fixed::operator + (const Fixed& other) const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed& other) const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator * (const Fixed& other) const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator / (const Fixed& other) const
{
    return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    fixedValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--()
{
    fixedValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

float Fixed::toFloat() const
{
    return static_cast<float>(fixedValue) / (1 << fractionalBits);
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
