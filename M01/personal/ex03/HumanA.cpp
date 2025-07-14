/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:39:53 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 11:40:10 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}
void	HumanA::attack(void)
{
	std::string type;

	std::cout << _name << " attacks with their ";
	type = _weapon.getType();
	if (type.empty())
		std::cout << "mind";
	else
		std::cout << type;
	std::cout << std::endl; 
}
