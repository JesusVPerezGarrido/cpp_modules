/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:21:32 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/09 13:03:25 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria	*inventory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		~MateriaSource(void);

		MateriaSource &operator = (const MateriaSource &copy);

		void learnMateria(AMateria*);
		AMateria* createMateria(const std::string &type);
};

#endif
