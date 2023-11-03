/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 05:04:03 by kkouaz            #+#    #+#             */
/*   Updated: 2023/11/03 07:01:21 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

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

Fixed :: ~Fixed(void)
{
    std :: cout << "Destructor called\n";
}