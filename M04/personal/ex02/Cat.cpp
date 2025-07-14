/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/22 13:48:35 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): brain(new Brain())
{
	std::cout << "Cat Default Constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copy): brain(new Brain())
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat Deconstructor called" << std::endl;
	delete brain;
}

Cat	&Cat::operator = (const Cat &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	*brain = *copy.brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
