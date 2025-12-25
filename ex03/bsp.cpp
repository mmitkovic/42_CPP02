/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:45:57 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/12/24 14:45:58 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed check_side (Point const &v1, Point const &v2, Point const &p)
{
    Fixed res;
    res = (p.getX() - v2.getX()) * (v1.getY() - v2.getY()) - (p.getY() - v2.getY()) * (v1.getX() - v2.getX());
    return res;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed w1 = check_side(a, b, point);
    Fixed w2 = check_side(b, c, point);
    Fixed w3 = check_side(c, a, point);

    if ((w1 > 0 && w2 > 0 && w3 > 0) || (w1 < 0 && w2 < 0 && w3 < 0))
        return true;
    return false;
}