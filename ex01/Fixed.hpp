#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int raw_value;
    static const int _bits = 8;
public:
    Fixed();
    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &src);
    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();
};

std::ostream& operator<<(std::ostream& out_strm, const Fixed& fixed_point);

#endif