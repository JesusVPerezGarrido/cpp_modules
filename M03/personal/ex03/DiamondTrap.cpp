/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:26:05 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 11:55:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	setName("Nameless_clap_name");
	name = "Nameless";
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	*this = copy;
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name)
{
	setName(new_name + "_clap_name");
	name = new_name;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap: String constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: Deconstructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << getName() << ": I am " << name << std::endl;
}
