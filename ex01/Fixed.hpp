/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:14:23 by kkouaz            #+#    #+#             */
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
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        ~Fixed(void);
};




#   endif