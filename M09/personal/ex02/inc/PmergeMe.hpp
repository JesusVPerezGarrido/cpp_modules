/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:45:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/15 17:23:20 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <exception>
#include <iterator>

template <typename T>
T	binary_search(T begin, T end, T insert);

class BlockVector
{
	public:
		BlockVector(void);
		BlockVector(const BlockVector &other);
		BlockVector(int &a);
		BlockVector(BlockVector &a, BlockVector &b);
		~BlockVector();

		BlockVector& operator = (const BlockVector &other);

		bool operator < (const BlockVector &other) const;
		bool operator > (const BlockVector &other) const;
		bool operator == (const BlockVector &other) const;

		int *getHead();
		std::vector<int *> &getContainer(void);

	private:
		int *head;
		std::vector<int *> container;
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
		void	mergeVector(std::vector<BlockVector> &);
		void	insertVector(std::vector<BlockVector> &);
		void	applyInsertVector(std::vector<BlockVector> &, std::vector<BlockVector> &);

		class InvalidSyntax : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

int	jacobsthal_number(const int n);

#include "PmergeMe.tpp"

#endif