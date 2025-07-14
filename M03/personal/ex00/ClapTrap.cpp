/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:30:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 14:23:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("Nameless"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string new_name): name(new_name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Deconstructor called" << std::endl;
}
ClapTrap	&ClapTrap::operator = (const ClapTrap &rct)
{
	if (this == &rct)
		return (*this);
	name = rct.name;
	hit_points = rct.hit_points;
	energy_points = rct.energy_points;
	attack_damage = rct.attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (energy_points < 1 || hit_points < 1)
	{
		std::cout << "ClapTrap " << name << " cant attack." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing ";
	std::cout << attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < 0)
	{
		std::cout << name << "took no damage!" << std::endl;
		return ;
	}
	hit_points -= amount;
	std::cout << name << " takes " << amount << " points of damage! ";
	std::cout << "It has " << hit_points << " hit points remaining" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= 0 || hit_points <= 0)
	{
		std::cout << name << " cant be repaired." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << name << " repairs itself, healing ";
	std::cout << amount << " points of damage! Now they have ";
	std::cout << hit_points << " hit points!" << std::endl;
}
