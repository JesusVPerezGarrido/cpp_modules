/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:36:50 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 16:25:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.h"

Fixed side(const Point point, const Point corner1, const Point corner2)
{
	return (point.getX() - corner2.getX()) * (corner1.getY() - corner2.getY()) - (corner1.getX() - corner2.getX()) * (point.getY() - corner2.getY());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed side1 = side(point, a, b);
	Fixed side2 = side(point, b, c);
	Fixed side3 = side(point, c, a);
	return (!((side1 < 0 || side2 < 0 || side3 < 0) && (side1 > 0 || side2 > 0 || side3 > 0)));
}
