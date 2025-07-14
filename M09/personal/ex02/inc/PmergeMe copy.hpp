/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:45:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/14 12:29:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <exception>
#include <iterator>

template <typename T>
typename T::iterator binarySearch(typename T::iterator begin, typename T::iterator end, typename T::iterator insert);

class PmergeMe
{
	public:
		static void	sort(std::string);
		
	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &pmm);
		~PmergeMe(void);
		
		const PmergeMe	&operator = (const PmergeMe &pmm);
		
		static void	sortVector(const std::string &str);
		static void	mergeInsertVector(std::vector<int> &c, int depth);
		static void	sortDeque(const std::string &str);

		static int	JacobsthalNumber(int n);

		class InvalidSyntax : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif