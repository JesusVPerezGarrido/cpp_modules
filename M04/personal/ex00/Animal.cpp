/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:16:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
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
