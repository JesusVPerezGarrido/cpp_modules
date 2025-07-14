/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:16:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Default Constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog Deconstructor called" << std::endl;
}

Dog	&Dog::operator = (const Dog &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
