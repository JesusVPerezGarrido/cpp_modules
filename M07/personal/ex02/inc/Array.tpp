/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:08:42 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/01 19:19:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) :
	_content(new T[0]),
	_size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) :
	_content(new T[n]),
	_size(n)
{}

template <typename T>
Array<T>::Array(const Array &copy) :
	_content(new T[copy._size]),
	_size(copy._size)
{
	for (std::size_t i = 0; i < copy._size; i++)
		_content[i] = copy[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _content;
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &copy)
{
	if (this == &copy)
		return (*this);
	delete[] _content;
	_content = new T[copy._size];
	_size = copy._size;
	for (std::size_t i = 0; i < copy._size; i++)
		_content[i] = copy[i];
	return (*this);
}

template <typename T>
T	&Array<T>::operator [] (std::size_t i)
{
	if (i >= _size)
		throw ArrayOutOfBounds();
	return (_content[i]);
}

template <typename T>
std::size_t	Array<T>::size(void)
{
	return (_size);
}

template <typename T>
const char	*Array<T>::ArrayOutOfBounds::what(void) const throw()
{
	return ("Invalid access out of bounds of the array");
}