/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:45:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/14 16:04:59 by jeperez-         ###   ########.fr       */
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

template <typename T>
class	BlockVector
{
	public:
		BlockVector(void);
		BlockVector(const BlockVector &);
		BlockVector(const T &, const T &);

		~BlockVector(void);

		const BlockVector	&operator = (const BlockVector &);
		bool				operator < (const BlockVector &) const;
		bool				operator > (const BlockVector &) const;

		const int &getHead(void) const;
		const std::vector<T> &getContainer(void) const;

	private:
		int	head;
		std::vector<T>	container;
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
std::ostream& operator<<(std::ostream& os, const BlockVector<T>& obj);

template <typename T>
int operator 0 (const int &, const BlockVector<T>&);

#endif