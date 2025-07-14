/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:46:24 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/03 15:04:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &t, int num)
{
	typename T::iterator it = std::find(t.begin(), t.end(), num);
	if (it == t.end())
		throw std::out_of_range("Number not in container");
	else
		return (it);
}

#endif