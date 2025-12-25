/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:45:47 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/12/24 14:45:48 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed   a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << "Min: " << Fixed::min( a, b ) << std::endl;
    std::cout << "Max: " << Fixed::max( a, b ) << std::endl;

    Fixed c(0.99f);
    std::cout << c << std::endl;

    Fixed d(10);
    std::cout << c * d << std::endl;

    if (d > c)
    {
        std::cout << "d: " << d << " > " << "c: " << c << std::endl; 
    }

    return 0;
}