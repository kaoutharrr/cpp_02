/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:51:32 by kkouaz            #+#    #+#             */
/*   Updated: 2023/11/03 00:03:58 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include<ostream>

class Fixed 
{
    private :
        int fixedPoint;
        static const int FractionalBits = 8;
    public :
        Fixed(void);
        Fixed(const Fixed &);
        Fixed(const int a);
        Fixed(const float b);
        Fixed& operator=(const Fixed &other);
        //comparing
       bool operator<(const Fixed& b) const;
       bool operator>(const Fixed& b) const;
       bool operator>=(const Fixed& b) const;
       bool operator<=(const Fixed& b) const;
       bool operator==(const Fixed& b) const;
        bool operator!=(const Fixed& b) const;
        //arithmetics
        Fixed operator+(const Fixed &b)const;
        Fixed operator-(const Fixed &b)const;
        Fixed operator*(const Fixed &b)const;
        Fixed operator/(const Fixed &b)const;

        //increment
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int nb);
        Fixed operator--(int nb);


        //functions
       static  Fixed& min(Fixed& a, Fixed& b);
       static  const Fixed& min(const Fixed& a, const Fixed& b);
       static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);


        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
        ~Fixed(void);
};




#   endif