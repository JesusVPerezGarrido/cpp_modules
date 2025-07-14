/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:21:32 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 12:30:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

typedef struct	sData
{
	int	x;
	int	y;
}		Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
	
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
		~Serializer(void);

		Serializer	&operator = (const Serializer &copy);
};

#endif