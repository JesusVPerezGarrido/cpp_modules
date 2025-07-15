/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:39:15 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/15 16:53:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
T	binary_search(T begin, T end, T insert)
{
	while (begin < end)
	{
		T mid = begin + std::distance(begin, end) / 2;
		if (*mid == *insert)
			return (mid);
		if (*mid < *insert)
			begin = mid + 1;
		if (*mid > *insert)
			end = mid - 1;
	}
	return (begin);
}