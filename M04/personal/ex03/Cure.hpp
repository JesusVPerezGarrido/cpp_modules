/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:39:05 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 12:51:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAL_HPP
# define HEAL_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);

		Cure	&operator = (const Cure &copy);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
