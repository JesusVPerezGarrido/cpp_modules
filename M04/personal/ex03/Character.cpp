/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:56:40 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/21 13:19:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): name(""), floor(new AMateria*[1]), floor_size(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	floor[0] = NULL;
}

Character::Character(const std::string &_name): name(_name), floor(new AMateria*[1]), floor_size(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	floor[0] = NULL;
}

Character::Character(const Character &copy): name(""), floor(new AMateria*[1]), floor_size(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	floor[0] = NULL;
	*this = copy;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
	for (int i = 0; i < floor_size; i++)
		delete floor[i];
	delete [] floor;
}

Character	&Character::operator = (const Character &copy)
{
	if (this == &copy)
		return (*this);
	name = copy.name;
	
	for (int i = 0; i < 4; i++)
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	for (int i = 0; i < 4; i++)
		if (copy.inventory[i])
			inventory[i] = copy.inventory[i]->clone();
	
	for (int i = 0; i < floor_size; i++)
		delete floor[i];
	delete [] floor;
	floor_size = copy.floor_size;
	floor = new AMateria*[floor_size + 1];
	for (int i = 0; i < floor_size; i++)
		floor[i] = copy.floor[i]->clone();
	floor[floor_size] = NULL;
	
	return (*this);
}

const std::string	&Character::getName(void) const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return;
	int i = 0;
	while (i < 4)
	{
		if (!inventory[i])
		{
			std::cout << "equipped materia " << m->getType() << " to space " << i << std::endl;
			inventory[i] = m;
			return;
		}
		i++;
	}
	std::cout << "no space for materia " << m->getType() << " to equip." << std::endl;
	drop(m);
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "unequip position " << idx << " not reachable" << std::endl;
	else if (inventory[idx])
	{
		std::cout << "unequipped: " << inventory[idx]->getType() << std::endl;
		drop(inventory[idx]);
		inventory[idx] = NULL;
	}
	else
		std::cout << "no materia at " << idx << " to unequip" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		std::cout << "use position " << idx << " not reachable" << std::endl;
	else if (inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "No materia at position " << idx << " to use" << std::endl;
}

void	Character::drop(AMateria *m)
{
	AMateria **tmp = new AMateria*[floor_size+2];
	for (int i = 0; i < floor_size; i++)
		tmp[i] = floor[i];
	tmp[floor_size] = m;
	floor_size++;
	tmp[floor_size] = NULL;
	delete [] floor;
	floor = tmp;
}
