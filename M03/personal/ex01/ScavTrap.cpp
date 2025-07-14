/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:08:28 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 14:03:49 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string new_name)
{
	setName(new_name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap: String constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Deconstructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &rst)
{
	if (this == &rst)
		return (*this);
	setName(rst.getName());
	setHitPoints(rst.getHitPoints());
	setEnergyPoints(rst.getEnergyPoints());
	setAttackDamage(rst.getAttackDamage());
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() < 1 || getHitPoints() < 1)
	{
		std::cout << "ScavTrap " << getName() << " cant attack." << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing ";
	std::cout << getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << getName() << ": Guard-Keeper mode initiated" << std::endl;
}
