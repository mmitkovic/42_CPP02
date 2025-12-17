#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int raw_value;
    static const int fract = 8;
public:
    Fixed();
    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &src);
    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();

    friend bool operator<(const Fixed& o1, const Fixed& o2);
    friend bool operator>(const Fixed& o1, const Fixed& o2);
    friend bool operator>=(const Fixed& o1, const Fixed& o2);
    friend bool operator<=(const Fixed& o1, const Fixed& o2);
    friend bool operator==(const Fixed& o1, const Fixed& o2);
    friend bool operator!=(const Fixed& o1, const Fixed& o2);

    friend Fixed operator+(const Fixed& o1, const Fixed& o2);
    friend Fixed operator-(const Fixed& o1, const Fixed& o2);
    friend Fixed operator/(const Fixed& o1, const Fixed& o2);
    friend Fixed operator*(const Fixed& o1, const Fixed& o2);

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    static const Fixed& min (const Fixed& o1, const Fixed& o2);
    static const Fixed& max (const Fixed& o1, const Fixed& o2);

    static Fixed& min (Fixed& o1, Fixed& o2);
    static Fixed& max (Fixed& o1, Fixed& o2);
};

std::ostream& operator<<(std::ostream& out_strm, const Fixed& raw_value);
std::istream& operator>>(std::istream& in_strm, Fixed& obj);

#endif