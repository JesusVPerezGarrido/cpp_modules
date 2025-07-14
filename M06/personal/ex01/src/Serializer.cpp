/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:31:09 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 12:35:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
}

Serializer::~Serializer(void)
{}

Serializer	&Serializer::operator = (const Serializer &copy)
{
	(void)copy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	serial = reinterpret_cast<uintptr_t>(ptr);
	return (serial);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*data = reinterpret_cast<Data*>(raw);
	return (data);
}