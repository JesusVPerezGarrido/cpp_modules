/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:23:46 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/19 15:08:21 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie constructed" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Deconstructor called to: ";
	std::cout << t::name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << t::name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string new_name)
{
	name = new_name;
}
