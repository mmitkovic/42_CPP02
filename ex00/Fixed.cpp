#include "Fixed.hpp"

void Fixed::setRawBits( int const raw )
{
    raw_value = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return raw_value;
}

Fixed::Fixed() : raw_value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& src) : raw_value(src.raw_value)
{
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &src)
    {
        this->raw_value = src.raw_value;
    }
    return *this;
}
