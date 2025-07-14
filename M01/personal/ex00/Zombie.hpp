/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:20:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 14:45:41 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		typedef	Zombie t;

		std::string	name;

	public:
		Zombie(std::string);
		~Zombie();

		void	announce(void);

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
