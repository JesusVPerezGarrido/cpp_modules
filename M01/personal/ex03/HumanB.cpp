/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:39:53 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 11:38:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << _name << " picked up a " << weapon.getType() << std::endl;
}

void	HumanB::attack(void)
{
	std::string type;

	std::cout << _name << " attacks with their ";
	if (_weapon)
	{
		type = _weapon->getType();
		if (type.empty())
			std::cout << "mind";
		else
			std::cout << type;
	}
		else
		std::cout << "fists";
	std::cout << std::endl;
}
