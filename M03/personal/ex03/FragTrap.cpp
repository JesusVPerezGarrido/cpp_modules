/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:08:28 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 15:28:11 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string new_name)
{
	setName(new_name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap: String constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Deconstructor called" << std::endl;
}

FragTrap	&FragTrap::operator = (const FragTrap &rft)
{
	if (this == &rft)
		return (*this);
	setName(rft.getName());
	setHitPoints(rft.getHitPoints());
	setEnergyPoints(rft.getEnergyPoints());
	setAttackDamage(rft.getAttackDamage());
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (getEnergyPoints() < 1 || getHitPoints() < 1)
	{
		std::cout << "FragTrap " << getName() << " cant attack." << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing ";
	std::cout << getAttackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << getName() << " Started a group High Five!" << std::endl;
}
