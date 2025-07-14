/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:24:18 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/28 12:13:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.h"

void	test(Point a, Point b, Point c, Point p)
{
	std::cout << "Test:" << std::endl;
	std::cout << "a" << a << " ";
	std::cout << "b" << b << " ";
	std::cout << "c" << c << " ";
	std::cout << "p" << p << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "point is inside the triangle!" << std::endl;
	else
		std::cout << "point is outside the triangle!" << std::endl;

}

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Point d(2, 2);
	Point e(4, 4);
	test(a, b, c, d);
	test(a, c, b, d);
	test(c, b, a, d);
	test(a, b, c, b);
	test(a, b, c, e);
	test(a, d, c, b);
	test(a, a, a, a);
}
