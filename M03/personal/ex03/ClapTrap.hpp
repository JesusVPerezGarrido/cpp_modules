/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:22:29 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 13:53:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &copy);
		ClapTrap(const std::string new_name);
		~ClapTrap(void);

		ClapTrap	&operator = (const ClapTrap &rct);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		std::string	setName(std::string new_name);
		int			setHitPoints(int new_hp);
		int			setEnergyPoints(int new_ep);
		int			setAttackDamage(int new_ad);

	private:
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
};

#endif
