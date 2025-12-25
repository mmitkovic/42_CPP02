/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:46:12 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/12/24 14:46:13 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <string>

void check(Point const a, Point const b, Point const c, Point const p, std::string status)
{
    std::cout << status << " : ";
    if (bsp(a, b, c, p))
        std::cout << "IN" << std::endl;
    else
        std::cout << "OUT" << std::endl;
}

int main()
{
    Point a(0.5,0.5);
    Point b(10.5, 0.5);
    Point c(0.5, 10.5);

    check(a, b, c, Point(2.2, 2.2), "Point inside");
    check(a, b, c, Point(0.5, 0.5), "Point on edge");
    check(a, b, c, Point(10.5, 10.5), "Point far outside");

    check(a, b, c, Point(5.5, 5.5), "5.5, 5.5");
    check(a, b, c, Point(5.4, 5.4), "5.4, 5.4");
    return 0;
}