/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:20:56 by kkouaz            #+#    #+#             */
/*   Updated: 2023/10/30 18:41:03 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

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
    (void)a;
    std :: cout  << "Int constructor called\n";
}

Fixed :: Fixed(const float f)
{
    (void)f;
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

// float Fixed :: toFloat(void) const
// {
//     return(1.555);
// }

// int Fixed :: toInt( void ) const
// {
//     return(0);
// }


Fixed :: ~Fixed(void)
{
    std :: cout << "Destructor called\n";
}