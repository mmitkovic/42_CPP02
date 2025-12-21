#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : raw_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num) : raw_value(num << _bits)
{
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float num) : raw_value((roundf(num * (1 << _bits))))
{
    std::cout << "Float constructor called" << std::endl;
}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &src) : raw_value(src.raw_value)
{
    std::cout << "Copy Constructor" << std::endl;
}

// COPY ASSIGNMENT OPERATOR
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

float Fixed::toFloat() const
{
    // return the division of the scaled (raw) number/value
    return (float)this->raw_value / (1 << _bits);
}

int Fixed::toInt() const
{
    return this->raw_value >> _bits;
}

bool Fixed::operator<(const Fixed& rghs) const { return (this->raw_value < rghs.raw_value); }
bool Fixed::operator>(const Fixed& rghs) const { return (this->raw_value > rghs.raw_value); }
bool Fixed::operator>=(const Fixed& rghs) const { return (this->raw_value >= rghs.raw_value); }
bool Fixed::operator<=(const Fixed& rghs) const { return (this->raw_value <= rghs.raw_value); }
bool Fixed::operator==(const Fixed& rghs) const { return (this->raw_value == rghs.raw_value); }
bool Fixed::operator!=(const Fixed& rghs) const { return (this->raw_value != rghs.raw_value); }

Fixed Fixed::operator+(const Fixed& rghs) const
{
    return Fixed(this->toFloat() + rghs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rghs) const
{
    return Fixed(this->toFloat() - rghs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rghs) const
{
    return Fixed(this->toFloat() / rghs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rghs) const
{
    return Fixed(this->toFloat() * rghs.toFloat());
}

// I/O stream --- Overloading stream insertion operators
std::ostream& operator<<(std::ostream& out_strm, const Fixed& raw_value)
{
    out_strm << raw_value.toFloat();
    return out_strm;
}
std::istream& operator>>(std::istream& in_strm, Fixed& obj)
{
    float temp_float;
    in_strm >> temp_float; // read from the stream
    Fixed temp_obj(temp_float);
    obj = temp_obj; 
    return in_strm;
}


Fixed& Fixed::operator++()
{
    this->raw_value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->raw_value += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->raw_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->raw_value -= 1;
    return temp;
}

const Fixed& Fixed::min(const Fixed& o1, const Fixed& o2)
{
    if (o1.raw_value < o2.raw_value)
        return o1;
    return o2;
}

const Fixed& Fixed::max(const Fixed& o1, const Fixed& o2)
{
    if (o1.raw_value > o2.raw_value)
        return o1;
    return o2;
}

Fixed& Fixed::min(Fixed& o1, Fixed& o2)
{
    if (o1.raw_value < o2.raw_value)
        return o1;
    return o2;
}

Fixed& Fixed::max(Fixed& o1, Fixed& o2)
{
    if (o1.raw_value > o2.raw_value)
        return o1;
    return o2;
}
