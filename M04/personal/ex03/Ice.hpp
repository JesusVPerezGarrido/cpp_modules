/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:39:05 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 12:53:09 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);

		Ice	&operator = (const Ice &copy);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
