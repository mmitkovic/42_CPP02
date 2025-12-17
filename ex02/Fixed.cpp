#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : raw_value(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int num) : raw_value(num << fract)
{
    std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float num) : raw_value(roundf((int)(num * 256)))
{
    std::cout << "Float constructor called\n";
}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &src) : raw_value(src.raw_value)
{
    std::cout << "Copy Constructor\n";
}

// COPY ASSIGNMENT OPERATOR
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy constructor called\n";
    if (this != &src)
    {
        this->raw_value = src.raw_value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

float Fixed::toFloat() const
{
    // return the division of the scaled (raw) number/value
    return (float)this->raw_value / (1 << 8);
}

int Fixed::toInt() const
{
    return this->raw_value >> fract;
}

bool operator<(const Fixed& o1, const Fixed& o2) { return (o1.raw_value < o2.raw_value); }
bool operator>(const Fixed& o1, const Fixed& o2) { return (o1.raw_value > o2.raw_value); }
bool operator>=(const Fixed& o1, const Fixed& o2) { return (o1.raw_value >= o2.raw_value); }
bool operator<=(const Fixed& o1, const Fixed& o2) { return (o1.raw_value <= o2.raw_value); }
bool operator==(const Fixed& o1, const Fixed& o2) { return (o1.raw_value == o2.raw_value); }
bool operator!=(const Fixed& o1, const Fixed& o2) { return (o1.raw_value != o2.raw_value); }

Fixed operator+(const Fixed& o1, const Fixed&o2)
{
    Fixed result;
    result.raw_value = o1.raw_value + o2.raw_value;
    return result;
}

Fixed operator-(const Fixed& o1, const Fixed&o2)
{
    Fixed result;
    result.raw_value = o1.raw_value - o2.raw_value;
    return result;
}

Fixed operator/(const Fixed& o1, const Fixed&o2)
{
    Fixed result;
    long long numerator_scaled = (long long)o1.raw_value << Fixed::fract;
    result.raw_value = numerator_scaled / o2.raw_value;
    return result;
}

Fixed operator*(const Fixed& o1, const Fixed&o2)
{
    Fixed result;
    result.raw_value = ((long long)o1.raw_value * o2.raw_value) >> Fixed::fract;
    return result;
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
