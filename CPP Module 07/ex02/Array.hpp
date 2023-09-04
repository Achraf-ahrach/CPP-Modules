#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <class T>

class Array
{
    private:
        T               *array;
        unsigned int    _size;
    public:
        Array() : _size(0), array(0)
        {
            std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
        }
        ~Array()
        {
            std::cout << "destructer\n";
            if (array != NULL)
                delete []array;
        }
        Array(Array &other)
        {
            std::cout << "Copy Constuctor called" << std::endl;
            this->array = NULL;
            *this = other;
        }
        Array(unsigned int n) : _size(n)
        {
            std::cout << "Constructor for an Array of size " << _size << " called" << std::endl;
            array = new T[_size];
        }
        Array &operator = (Array &other)
        {
            if (this == &other)
                return (*this);
            if (this->array != NULL)
                delete []array;
            if (other._size != 0)
            {
                this->_size = other._size;
                this->array = new T[this->_size];
                for(unsigned int i = 0; i < this->_size; i++)
                    this->array[i] = other.array[i];
            }
            return (*this);
        }
        T &operator[](unsigned int index)
        {
            if (index >= _size)
            {
                std::cout << "index: " << index << std::endl;
                throw std::out_of_range("Invalid Index Exception !");
            }
            return (array[index]);
        }
        unsigned int size() const
        {
            return (_size);
        }
};

#endif