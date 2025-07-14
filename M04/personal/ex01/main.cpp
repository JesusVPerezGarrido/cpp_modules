/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:30:12 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/21 13:20:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	const int size = ZOO_SIZE;
	Animal	*zoo[size];

	for (int i = 0; i < size / 2; i++)
		zoo[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		zoo[i] = new Cat();

	for (int i = 0; i < size; i++)
		zoo[i]->makeSound();

	for (int i = 0; i < size; i++)
		delete zoo[i];
	std::cout << "DEBUG: Testing Deep Copy" << std::endl;
	Dog	doggo;
	{
		Dog test = doggo;
	}
}
