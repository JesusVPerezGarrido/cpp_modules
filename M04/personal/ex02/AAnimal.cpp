/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:05:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;
	std::cout << "AAnimal Copy Constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Deconstructor called" << std::endl;
}

const std::string	AAnimal::getType(void) const
{
	return(type);
}

AAnimal	&AAnimal::operator = (const AAnimal &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "* ilegible sounds *" << std::endl;
}
