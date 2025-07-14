/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:13:48 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/08 11:59:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public:
		virtual	~ICharacter(void);
		
		virtual std::string	const &getName() const = 0;
		virtual void		equip (AMateria *m) =0;
		virtual void		unequip(int idx) =0;
		virtual void		use(int idx, ICharacter &target) = 0;
};

#endif
