/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:12:56 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}

WrongCat	&WrongCat::operator = (const WrongCat &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "sassy cat noises" << std::endl;
}
