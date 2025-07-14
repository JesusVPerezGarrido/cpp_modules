/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:08:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 14:36:15 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int number;
		static const int point = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed	&operator = (const Fixed &copy);
		~Fixed();

		int getRawBits(void) const;
		int setRawBits(const int raw);
};

#endif 
