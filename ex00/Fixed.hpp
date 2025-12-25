/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:44:55 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/12/24 14:44:56 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    int raw_value;
    static const int _bits = 8;
public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed &operator=(const Fixed &src);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif