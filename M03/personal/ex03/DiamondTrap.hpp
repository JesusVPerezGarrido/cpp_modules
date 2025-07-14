/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:26:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 15:22:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string new_name);
		~DiamondTrap(void);

		using	ClapTrap::operator =;
		using	ScavTrap::attack;
		void	whoAmI(void) const;
	private:
		std::string name;
};

#endif
