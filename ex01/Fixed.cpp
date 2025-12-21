#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : raw_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num) : raw_value(num << _bits)
{
    std::cout << "Int constructor called\n" << std::endl;
}
Fixed::Fixed(const float num) : raw_value((roundf(num * (1 << _bits))))
{
    std::cout << "Float constructor called" << std::endl;
}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed& src) : raw_value(src.raw_value)
{
    std::cout << "Copy constructor called" << std::endl;
}

// COPY ASSIGNMENT CONSTRUCTOR
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &src)
    {
        this->raw_value = src.raw_value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt() const
{
    return this->raw_value >> _bits;
}

float Fixed::toFloat() const
{
    return (float)this->raw_value / (1 << 8);
}

std::ostream& operator<<(std::ostream& out_strm, const Fixed& obj)
{
    out_strm << obj.toFloat();
    return out_strm;
}
