#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(const float x_val, const float y_val);
    Point(const Point &src);
    Point &operator=(const Point &src);
    ~Point();

    Fixed getX( void ) const ;
    Fixed getY( void ) const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif