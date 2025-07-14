/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:04 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 15:06:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(copy.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed	&Fixed::operator = (const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);

	number = copy.getRawBits();
	return (*this); 
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (number);
}

int	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	number = raw;
	return (number);
}
