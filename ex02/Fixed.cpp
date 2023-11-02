/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:52:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/11/02 05:05:54 by kkouaz           ###   ########.fr       */
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
    std :: cout << FixedPoint; 
}

Fixed :: Fixed(const float f)
{
   
    FixedPoint = roundf(f * (1 << FractionalBits));
     std :: cout << FixedPoint; 
    std :: cout << "Float constructor called\n";
}

//comapring
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

bool Fixed :: operator<(const Fixed& b) const
{
        return (this->FixedPoint < b.FixedPoint);
}

bool Fixed :: operator>(const Fixed& b) const
{
    return (this->FixedPoint > b.FixedPoint);
}

bool Fixed :: operator<=(const Fixed& b) const
{
    return (this->FixedPoint <= b.FixedPoint);
}
bool Fixed :: operator>=(const Fixed& b) const
{
    return (this->FixedPoint >= b.FixedPoint);
}

bool Fixed :: operator==(const Fixed& b) const
{
    return (this->FixedPoint == b.FixedPoint);
}

bool Fixed :: operator!=(const Fixed& b) const
{
    return (this->FixedPoint != b.FixedPoint);
}


//arithmetics 
Fixed  Fixed :: operator+(const Fixed& b) const
{
    Fixed neww;
    int sum = this->FixedPoint + b.FixedPoint;
    neww.setRawBits(sum);
    return(neww);
}
Fixed  Fixed :: operator-(const Fixed& b) const
{
    Fixed neww;
    int sum = this->FixedPoint - b.FixedPoint;
    neww.setRawBits(sum);
    return(neww);
}

Fixed  Fixed :: operator*(const Fixed& b) const
{
    Fixed neww;
    int sum = (FixedPoint * b.FixedPoint) >> 8;
    neww.setRawBits(sum);
    return(neww);
}

Fixed  Fixed :: operator/(const Fixed& b) const
{
    Fixed neww;
    int sum = (this->FixedPoint / b.FixedPoint) << 8;
    neww.setRawBits(sum);
    return(neww);
}

//incrementation/decrementation

Fixed& Fixed :: operator++()
{
    this->FixedPoint+=1;
    return(*this);
}

Fixed& Fixed :: operator--()
{
    this->setRawBits(this->FixedPoint - 1);
    return(*this);
}


Fixed Fixed :: operator++(int nb)
{
    nb = 1;
    Fixed copy = *this;
    this->FixedPoint+=nb;
    return(copy);
}

Fixed Fixed :: operator--(int nb)
{
    nb = 1;
    Fixed copy = *this;
    this->FixedPoint-=nb;
    return(copy);
}


//functions

Fixed& Fixed :: min(Fixed& a, Fixed& b)
{
    if (a < b)
        return(a);
    return(b);
}

const Fixed& Fixed :: min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return(a);
    return(b);
}

Fixed& Fixed :: max(Fixed& a, Fixed& b)
{
    if (a < b)
        return(b);
    return(a);
}

const Fixed& Fixed :: max(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return(b);
    return(a);
}


Fixed :: ~Fixed(void)
{
    std :: cout << "Destructor called\n";
}