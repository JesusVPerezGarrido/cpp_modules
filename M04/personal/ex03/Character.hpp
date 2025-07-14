/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:54:40 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 13:31:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		std::string	name;
		AMateria	*inventory[4];
		AMateria	**floor;
		int			floor_size;

		void	drop(AMateria *m);

	public:
		Character(void);
		Character(const std::string &_name);
		Character(const Character &copy);
		~Character(void);

		Character	&operator = (const Character &copy);

		std::string	const &getName() const;
		void		equip (AMateria *m);
		void		unequip(int idx);
		void		use(int idx, ICharacter &target);
};

#endif
