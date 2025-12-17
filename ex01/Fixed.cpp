#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int num) : fixed_point(num << fract)
{
    std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float num) : fixed_point((int)(num * 256))
{
    std::cout << "Float constructor called\n";
}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed& src) : fixed_point(src.fixed_point)
{
    std::cout << "Copy constructor called\n";
}

// COPY ASSIGNMENT CONSTRUCTOR
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy constructor called\n";
    if (this != &src)
    {
        this->fixed_point = src.fixed_point;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::toInt() const
{
    return this->fixed_point >> fract;
}

float Fixed::toFloat() const
{
    return (float)this->fixed_point / (1 << 8);
}

std::ostream& operator<<(std::ostream& out_strm, const Fixed& obj)
{
    out_strm << obj.toFloat();
    return out_strm;
}
