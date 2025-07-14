/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:30:12 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 15:01:46 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*Bug = new Animal();
	const Animal		*Mittens = new Cat();
	const Animal		*Ruffle = new Dog();
	const WrongAnimal		*Hycothotl = new WrongCat();

	std::cout << Bug->getType() << std::endl;
	std::cout << Mittens->getType() << std::endl;
	std::cout << Ruffle->getType() << std::endl;
	std::cout << Hycothotl->getType() << std::endl;
	
	Bug->makeSound();
	Mittens->makeSound();
	Ruffle->makeSound();
	Hycothotl->makeSound();

	delete Bug;
	delete Mittens;
	delete Ruffle;
	delete Hycothotl;
}
