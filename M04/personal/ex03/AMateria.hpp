/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:09:32 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 12:48:47 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void);
		AMateria(const AMateria &copy);
		AMateria(std::string const &type);

		virtual ~AMateria();

		AMateria	&operator = (const AMateria &copy);

		std::string const	&getType(void) const;

		virtual AMateria	*clone(void) const =0;
		virtual void		use(ICharacter &target);
};

#endif
