/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:38:55 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 12:52:26 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria::AMateria("cure")
{}

Cure::Cure(const Cure &copy)
{
	*this = copy;
}

Cure::~Cure(void)
{}

Cure	&Cure::operator = (const Cure &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.getType();
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	Cure *clone = new Cure();
	return (clone);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
