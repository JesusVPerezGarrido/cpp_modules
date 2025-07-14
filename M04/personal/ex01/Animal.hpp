/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:07:32 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:17:23 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal &operator = (const Animal &copy);
		
		const std::string	getType(void) const;
		virtual void		makeSound(void) const;
	protected:
		std::string	type;
};

#endif
