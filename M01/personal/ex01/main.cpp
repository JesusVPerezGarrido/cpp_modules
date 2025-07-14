/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:37:41 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/19 15:13:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		index;

	horde = zombieHorde(5, "amet");
	index = 0;
	while (index < 5)
	{
		horde[index].announce();
		index++;
	}
	delete [] horde;
}
