/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:04 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 12:03:49 by jeperez-         ###   ########.fr       */
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
	*this = copy;
}
Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(nbr << point);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(nbr * (1 << point)));
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

	setRawBits(copy.getRawBits());
	return (*this); 
}

int	Fixed::getRawBits(void) const
{
	return (number);
}

int	Fixed::setRawBits(const int raw)
{
	number = raw;
	return (number);
}


float	Fixed::toFloat(void) const
{
	return ((float)number / (1 << point));
}

int	Fixed::toInt(void) const
{
	return (number >> point);
}

std::ostream	&operator << (std::ostream &out, const Fixed & fixed)
{
	out << fixed.toFloat();
	return (out);
}
