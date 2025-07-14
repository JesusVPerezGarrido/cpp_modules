/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 15:03:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

const std::string	WrongAnimal::getType(void) const
{
	return(type);
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* eldritch sounds *" << std::endl;
}
