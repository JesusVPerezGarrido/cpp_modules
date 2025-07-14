/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:42:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 16:50:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &T1, T &T2)
{
	T	placeholder;
	placeholder = T1;
	T1 = T2;
	T2 = placeholder;
}

template <typename T> T max(const T &T1, const T &T2)
{
	if (T1 > T2)
		return (T1);
	return (T2);
}

template <typename T> T min(const T &T1, const T &T2)
{
	if (T1 < T2)
		return (T1);
	return (T2);
}

#endif