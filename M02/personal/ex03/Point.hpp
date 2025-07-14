/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:38:09 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 16:19:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &p);
		~Point(void);

		Point	&operator = (const Point &p);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

std::ostream	&operator << (std::ostream &out, const Point &point);

#endif
