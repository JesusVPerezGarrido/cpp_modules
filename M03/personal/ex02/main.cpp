/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 14:14:16 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "Hello world!" << std::endl;
	ScavTrap	Jake("Jake");
	ClapTrap	Peter("Peter");
	FragTrap	Thomas("Thomas");
	
	Jake.guardGate();
	Peter.attack("Ooze");
	Jake.attack("Big Head");
	Thomas.attack("Squid Man");
	Thomas.highFivesGuys();
}
