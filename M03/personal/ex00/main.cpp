/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 12:57:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "Hello world!" << std::endl;
	ClapTrap NeimLee;
	ClapTrap Bob("Bob");
	ClapTrap BobTwin(Bob);

	NeimLee.takeDamage(2);
	BobTwin.attack("Slime Ooze");
	BobTwin.beRepaired(2);
	BobTwin.attack("Slime Ooze");
	BobTwin.beRepaired(2);
	BobTwin.attack("Slime Ooze");
	BobTwin.beRepaired(2);
	BobTwin.attack("Slime Ooze");
	BobTwin.beRepaired(2);
	BobTwin.attack("Slime Ooze");
	BobTwin.beRepaired(2);
	BobTwin.attack("Slime Ooze");
}
