/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:38:39 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 16:20:04 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{}

Point::Point(const float x, const float y): _x(x), _y(y)
{}

Point::Point(const Point &p): _x(p.getX()), _y(p.getY())
{}

Point::~Point(void)
{}

Point	&Point::operator = (const Point &p)
{
	std::cout << "thx 42! thanks to the subject requiring x and y to be constant we can't change it, so this operation is useless!" << std::endl;
	if (this == &p)
		return (*this);
	return (*this);
}

Fixed	Point::getX(void) const
{
	return(_x);
}

Fixed	Point::getY(void) const
{
	return(_y);
}

std::ostream	&operator << (std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << "," << point.getY() << ")";
	return (out);
}
