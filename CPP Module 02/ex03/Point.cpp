#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point(){}

Point::Point(const float x, const float y) : x(x) , y(y){}

Point::Point(const Point& other) : x(other.getX()), y(other.getY()){}

Point& Point::operator = (const Point& other)
{
    (Fixed)this->x = other.x;
    (Fixed)this->y = other.y;

    return (*this);
}

const Fixed& Point::getX() const
{
    return (this->x);
}

const Fixed& Point::getY() const
{
    return (this->y);
}