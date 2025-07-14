/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:09:18 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 14:17:11 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"

class FragTrap: ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &copy);
		FragTrap(const std::string new_name);
		
		~FragTrap(void);

		FragTrap	&operator = (const FragTrap &rft);

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif
