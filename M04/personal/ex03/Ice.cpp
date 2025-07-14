/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:38:55 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 12:54:25 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria::AMateria("ice")
{
}

Ice::Ice(const Ice &copy)
{
	*this = copy;
}

Ice::~Ice(void)
{}

Ice	&Ice::operator = (const Ice &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.getType();
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	Ice *clone = new Ice();
	return (clone);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}
