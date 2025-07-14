/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:20:57 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 15:18:10 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

MateriaSource &MateriaSource::operator = (const MateriaSource &copy)
{
	if (this == &copy)
		return (*this);

	for (int i = 0; i < 4; i++)
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	for (int i = 0; i < 4; i++)
		if (copy.inventory[i])
			inventory[i] = copy.inventory[i]->clone();
			
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	int i = 0;
	while (i < 4)
	{
		if (!inventory[i])
		{
			std::cout << "learning materia " << m->getType() << " at space " << i << std::endl;
			inventory[i] = m;
			return ;
		}
		i++;
	}
	std::cout << "no space to learn materia " << m->getType() << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	int i = 0;
	while (i < 4)
	{
		if (inventory[i] && !inventory[i]->getType().compare(type))
		{
			std::cout << "created materia " << type << std::endl;
			return (inventory[i]->clone());
		}
		i++;
	}
	std::cout << "No materia found for " << type << std::endl;
	return (NULL);
}
