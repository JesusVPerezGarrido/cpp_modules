/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:55:11 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/01 19:14:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copy);
		~Array(void);

		Array	&operator = (const Array &copy);
		T		&operator [] (std::size_t i);

		std::size_t	size(void);
	private:
		T			*_content;
		std::size_t	_size;

		class ArrayOutOfBounds : public std::exception
		{
		public:
			const char	*what(void) const throw();
		};
		
};

# include "Array.tpp"

#endif