/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:39:15 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/16 12:08:36 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
T	binary_search(T begin, T end, T insert)
{
	while (begin < end)
	{
		T mid = begin + (end - begin) / 2;
		if (*mid < *insert)
			begin = mid + 1;
		else
			end = mid;
	}
	if (*begin < *insert)
		return (begin + 1);
	return (begin);
}