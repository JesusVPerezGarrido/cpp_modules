/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:05:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Deconstructor called" << std::endl;
}

const std::string	Animal::getType(void) const
{
	return(type);
}

Animal	&Animal::operator = (const Animal &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "* ilegible sounds *" << std::endl;
}
