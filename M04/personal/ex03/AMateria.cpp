/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:36:08 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 12:49:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	type.clear();
}

AMateria::AMateria(const AMateria &copy): type(copy.getType())
{
}

AMateria::AMateria(const std::string &_type): type(_type)
{
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator = (const AMateria &copy)
{
	if (this == &copy)
		return (*this);
	type = copy.getType();
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* casted wild magic at " << target.getName() << " *" <<std::endl;
}
