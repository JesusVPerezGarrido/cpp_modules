/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:46:24 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 14:50:24 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain(void)
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

Brain	&Brain::operator = (const Brain &copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	return (*this);
}
