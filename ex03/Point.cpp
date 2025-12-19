#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
    // std::cout << "Default Constructor called\n";
}

Point::Point(const float x_val, const float y_val) : _x(x_val), _y(y_val)
{
    //body
}

// copy constructor
Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
    // std::cout << "Copy Constructor called\n";
}

// copy assignment operator
Point &Point::operator=(const Point &src)
{
    // std::cout << "Copy Assignment Operator called \n";
    (void)src;
    return *this;
}

Point::~Point()
{
    // std::cout << "Deconstructor called\n";
}

// getters
Fixed Point::getX() const
{
    return this->_x;
}

Fixed Point::getY() const 
{
    return this->_y;
}

