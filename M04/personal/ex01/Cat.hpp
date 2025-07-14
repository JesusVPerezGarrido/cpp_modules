/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:09:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/07 14:53:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		~Cat(void);

		Cat &operator = (const Cat &copy);

		void makeSound(void) const;
	private:
		Brain	*brain;
};

#endif
