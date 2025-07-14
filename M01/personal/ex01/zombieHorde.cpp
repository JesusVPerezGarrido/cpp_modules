/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:56:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/19 15:12:56 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int	index;
	Zombie	*horde;
	
	horde = new Zombie[N];
	index = 0;
	while (index < N)
	{
		horde[index].set_name(name);
		index++;
	}
	return (horde);
}
