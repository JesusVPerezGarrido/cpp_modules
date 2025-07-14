/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:04 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 15:33:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): number(0)
{}

Fixed::Fixed(const Fixed &copy)
{
	setRawBits(copy.getRawBits());
}
Fixed::Fixed(const int nbr)
{
	setRawBits(nbr << point);
}

Fixed::Fixed(const float nbr)
{
	setRawBits(roundf(nbr * (1 << point)));
}

Fixed::~Fixed()
{}

Fixed	&Fixed::operator = (const Fixed &copy)
{
	if (this == &copy)
		return (*this);

	number = copy.getRawBits();
	return (*this); 
}

bool	Fixed::operator > (const Fixed &fixed) const
{
	return (toFloat() > fixed.toFloat());
}

bool	Fixed::operator < (const Fixed &fixed) const
{
	return (fixed > *this);
}

bool	Fixed::operator >= (const Fixed &fixed) const
{
	return (!(*this < fixed));
}

bool	Fixed::operator <= (const Fixed &fixed) const
{
	return (!(*this > fixed));
}

bool	Fixed::operator == (const Fixed &fixed) const
{
	return (toFloat() == fixed.toFloat());
}

bool	Fixed::operator != (const Fixed &fixed) const
{
	return (!(*this == fixed));
}

Fixed&	Fixed::operator ++ ()
{
	number++;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed old = *this;
	++(*this);
	return (old);
}

Fixed&	Fixed::operator -- ()
{
	number--;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed old = *this;
	--(*this);
	return (old);
}

Fixed	Fixed::operator + (const Fixed &fixed)
{
	Fixed ret(toFloat() + fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator - (const Fixed &fixed)
{
	Fixed ret(toFloat() - fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator * (const Fixed &fixed)
{
	Fixed ret(toFloat() * fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator / (const Fixed &fixed)
{
	Fixed ret(toFloat() / fixed.toFloat());
	return (ret);
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

Fixed	&Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed	&Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

std::ostream	&operator << (std::ostream &out, const Fixed & fixed)
{
	out << fixed.toFloat();
	return (out);
}

