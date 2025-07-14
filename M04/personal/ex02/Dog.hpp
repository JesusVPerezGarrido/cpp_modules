/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:09:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 15:49:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Dog: public AAnimal
{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog &operator = (const Dog &copy);

		void makeSound(void) const;
	private:
		Brain	*brain;
};

#endif
