/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/03 14:05:49 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "Hello world!" << std::endl;
	ScavTrap Jake("Jake");
	ClapTrap Peter("Peter");
	
	Jake.guardGate();
	Peter.attack("Ooze");
	Jake.attack("BigHead");
}
