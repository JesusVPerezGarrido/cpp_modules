/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:45:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/15 12:30:51 by jeperez-         ###   ########.fr       */
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

class	BlockVector
{
	public:
		BlockVector(void);
		BlockVector(const BlockVector &);
		BlockVector(const int &, const int &);
		BlockVector(const BlockVector &, const BlockVector &);

		~BlockVector(void);

		const BlockVector	&operator = (const BlockVector &);
		bool				operator < (const BlockVector &) const;
		bool				operator > (const BlockVector &) const;

		const int &getHead(void) const;
		const std::vector<int> &getContainer(void) const;

	private:
		int	head;
		std::vector<int>	container;
};

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &);
		PmergeMe(const std::string &);
		~PmergeMe(void);

		const PmergeMe	&operator = (const PmergeMe &);

		void	sort(void);
		
	private:
		std::string	str;
	
		void	sortVector(void);
		template <typename T>
		void	mergeVector(std::vector<T> &);
		template <typename T>
		void	insertVector(std::vector<T>);

		//void	sortDeque(void);

		int	JacobsthalNumber(int n);

		class InvalidSyntax : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

template <typename T>
std::ostream& operator<<(std::ostream&, const BlockVector &);

#endif