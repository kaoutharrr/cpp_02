/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:52:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/11/03 07:31:13 by kkouaz           ###   ########.fr       */
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

//comapring
bool Fixed :: operator<(const Fixed& b) const
{
        return (this->fixedPoint < b.fixedPoint);
}

bool Fixed :: operator>(const Fixed& b) const
{
    return (this->fixedPoint > b.fixedPoint);
}

bool Fixed :: operator<=(const Fixed& b) const
{
    return (this->fixedPoint <= b.fixedPoint);
}
bool Fixed :: operator>=(const Fixed& b) const
{
    return (this->fixedPoint >= b.fixedPoint);
}

bool Fixed :: operator==(const Fixed& b) const
{
    return (this->fixedPoint == b.fixedPoint);
}

bool Fixed :: operator!=(const Fixed& b) const
{
    return (this->fixedPoint != b.fixedPoint);
}

//arithmetics 
Fixed  Fixed :: operator+(const Fixed& b) const
{
    Fixed neww;
    int sum = this->fixedPoint + b.fixedPoint;
    neww.setRawBits(sum);
    return(neww);
}
Fixed  Fixed :: operator-(const Fixed& b) const
{
    Fixed neww;
    int sum = this->fixedPoint - b.fixedPoint;
    neww.setRawBits(sum);
    return(neww);
}

Fixed  Fixed :: operator*(const Fixed& b) const
{
    Fixed neww;
    int sum = (fixedPoint * b.fixedPoint) >> 8;
    neww.setRawBits(sum);
    return(neww);
}

Fixed  Fixed :: operator/(const Fixed& b) const
{
    Fixed neww;
    int sum = (this->fixedPoint / b.fixedPoint) << 8;
    neww.setRawBits(sum);
    return(neww);
}

//incrementation/decrementation

Fixed& Fixed :: operator++()
{
    this->fixedPoint+=1;
    return(*this);
}

Fixed& Fixed :: operator--()
{
    this->setRawBits(this->fixedPoint - 1);
    return(*this);
}


Fixed Fixed :: operator++(int nb)
{
    nb = 1;
    Fixed copy = *this;
    this->fixedPoint+=nb;
    return(copy);
}

Fixed Fixed :: operator--(int nb)
{
    nb = 1;
    Fixed copy = *this;
    this->fixedPoint-=nb;
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