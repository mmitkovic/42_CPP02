/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:46:25 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/12/24 14:46:26 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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