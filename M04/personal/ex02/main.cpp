/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:30:12 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:49:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
//	const AAnimal		*Bug = new AAnimal();
	const AAnimal		*Mittens = new Cat();
	const AAnimal		*Ruffle = new Dog();

	std::cout << Mittens->getType() << std::endl;
	std::cout << Ruffle->getType() << std::endl;
	
	Mittens->makeSound();
	Ruffle->makeSound();

	delete Mittens;
	delete Ruffle;
}
