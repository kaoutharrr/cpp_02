/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:52:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/10/31 22:52:42 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"
#include<cmath>

Fixed :: Fixed(void)
{
    FixedPoint = 0;
    std :: cout << "Default constructor called \n";
}

Fixed :: Fixed(const Fixed& F)
{
    FixedPoint = F.FixedPoint;
    std :: cout << "copy constructor called \n";
}


Fixed :: Fixed(const int a)
{
    FixedPoint = a << FractionalBits ;
    std :: cout  << "Int constructor called\n";
}

Fixed :: Fixed(const float f)
{
    FixedPoint = roundf(f * (1 << FractionalBits));
    std :: cout << "Float constructor called\n";
}

Fixed& Fixed :: operator=(const Fixed& other)
{
    std :: cout << "Copy assignment operator called \n";
    if(this == &other)
        return(*this);
    FixedPoint = other.FixedPoint;
    return(*this);
}

int Fixed :: getRawBits( void )const
{
    std :: cout << "getRawBits member function called \n";
    return(FixedPoint);
}

void Fixed :: setRawBits( int const raw )
{
    std :: cout << "setRawBits member function called \n";
   FixedPoint = raw;
}

float Fixed :: toFloat(void) const
{
    float g = (float)FixedPoint /( 1 <<  FractionalBits);
    return(g);
}

int Fixed :: toInt( void ) const
{
    return(FixedPoint >> FractionalBits);
}

Fixed :: ~Fixed(void)
{
    std :: cout << "Destructor called\n";
}