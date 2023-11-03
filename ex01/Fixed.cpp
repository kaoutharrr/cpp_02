/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:20:56 by kkouaz            #+#    #+#             */
/*   Updated: 2023/11/03 01:23:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"
#include<cmath>

Fixed :: Fixed(void)
{
    fixedPoint = 0;
    std :: cout << "Default constructor called \n";
}

Fixed :: Fixed(const Fixed& F)
{
    std :: cout << "copy constructor called \n";
    *this = F;
}


Fixed :: Fixed(const int a)
{
    fixedPoint = a << FractionalBits ;
    std :: cout  << "Int constructor called\n";
}

Fixed :: Fixed(const float f)
{
    fixedPoint = roundf(f * (1 << FractionalBits));
    std :: cout << "Float constructor called\n";
}

Fixed& Fixed :: operator=(const Fixed& other)
{
    std :: cout << "Copy assignment operator called \n";
    if(this == &other)
        return(*this);
    fixedPoint = other.getRawBits();
    return(*this);
}

int Fixed :: getRawBits( void )const
{
    std :: cout << "getRawBits member function called \n";
    return(fixedPoint);
}

void Fixed :: setRawBits( int const raw )
{
    std :: cout << "setRawBits member function called \n";
   fixedPoint = raw;
}

float Fixed :: toFloat(void) const
{
    float g = (float)fixedPoint /( 1 <<  FractionalBits);
    return(g);
}

int Fixed :: toInt( void ) const
{
    return(fixedPoint >> FractionalBits);
}

Fixed :: ~Fixed(void)
{
    std :: cout << "Destructor called\n";
}