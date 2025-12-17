#include "Fixed.hpp"

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return fixed_point;
}

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& src) : fixed_point(src.fixed_point)
{
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &src)
    {
        this->fixed_point = src.fixed_point;
    }
    return *this;
}
