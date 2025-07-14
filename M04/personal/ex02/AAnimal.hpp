/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:07:32 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:40:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal()=0;

		AAnimal &operator = (const AAnimal &copy);
		
		const std::string	getType(void) const;
		virtual void		makeSound(void) const =0;
	protected:
		std::string	type;
};

#endif
