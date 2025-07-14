/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:38:28 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 12:43:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "- creating Structure" << std::endl;
	Data *d = new Data();
	d->x = 4;
	d->y = 2;
	std::cout << "Data(x: " << d->x << ", y: " << d->y << ")" << std::endl;

	std::cout << "- serializing pointer" << std::endl;
	uintptr_t raw = Serializer::serialize(d);

	std::cout << "- losing original pointer" << std::endl;
	d = 0;
	

	std::cout << "- deserializing pointer" << std::endl;
	d = Serializer::deserialize(raw);
	
	std::cout << "- recovered pointer" << std::endl;
	std::cout << "Data(x: " << d->x << ", y: " << d->y << ")" << std::endl;

	delete d;
}