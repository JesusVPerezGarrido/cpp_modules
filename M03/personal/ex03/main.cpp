/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 15:27:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "Hello world!" << std::endl;
	ClapTrap	Peter("Peter");
	ScavTrap	Jake("Jake");
	FragTrap	Thomas("Thomas");
	DiamondTrap Damian("Damian");
	
	Jake.guardGate();
	Peter.attack("Ooze");
	Jake.attack("Big Head");
	Thomas.attack("Squid Man");
	Damian.attack("Fungi Colony");
	Thomas.highFivesGuys();
	Damian.whoAmI();
}
