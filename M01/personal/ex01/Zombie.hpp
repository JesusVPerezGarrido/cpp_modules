/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:20:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/19 15:09:15 by jeperez-         ###   ########.fr       */
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
		Zombie(void);
		~Zombie();

		void	set_name(std::string new_name);
		void	announce(void);

};

Zombie	*zombieHorde(int N, std::string name);

#endif
