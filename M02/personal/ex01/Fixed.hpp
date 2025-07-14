/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:08:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 14:46:22 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		typedef	Fixed t;
		int number;
		static const int point = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int nbr);
		Fixed(const float nbr);
		
		Fixed & operator = (const Fixed &fixed);
		
		~Fixed();
		
		int getRawBits(void) const;
		int setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator << (std::ostream &out, const Fixed & fixed);

#endif 
