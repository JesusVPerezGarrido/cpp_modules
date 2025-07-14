/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:08:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 15:12:10 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int number;
		static const int point = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int nbr);
		Fixed(const float nbr);
		
		Fixed & operator = (const Fixed &fixed);
		
		bool operator > (const Fixed &fixed) const;
		bool operator < (const Fixed &fixed) const;
		bool operator >= (const Fixed &fixed) const;
		bool operator <= (const Fixed &fixed) const;
		bool operator == (const Fixed &fixed) const;
		bool operator != (const Fixed &fixed) const;
		
		Fixed& operator ++ (void); // ++a
		Fixed operator ++ (int); // a++ (0);
		Fixed& operator -- (void);
		Fixed operator -- (int);
		
		Fixed operator + (const Fixed &fixed);
		Fixed operator - (const Fixed &fixed);
		Fixed operator * (const Fixed &fixed);
		Fixed operator / (const Fixed &fixed);
		
		~Fixed();
		
		int getRawBits(void) const;
		int setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed& f1, Fixed& f2);
		static Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		static Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream & operator << (std::ostream &out, const Fixed & fixed);

#endif 
