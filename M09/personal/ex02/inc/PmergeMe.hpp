/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:45:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/16 14:45:45 by jeperez-         ###   ########.fr       */
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
#include <ctime>
#include <exception>
#include <iterator>

template <typename T>
class Block
{
	public:
		Block(void);
		Block(const Block &other);
		Block(int &a);
		Block(Block &a, Block &b);
		~Block();

		Block	&operator = (const Block &other);
		bool	operator < (const Block &other) const;
		bool	operator > (const Block &other) const;
		bool	operator == (const Block &other) const;

		int	*getHead();
		T	&getContainer(void);

	private:
		int	*head;
		T	container;
};

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &);
		PmergeMe(int, char **);
		~PmergeMe(void);

		const PmergeMe	&operator = (const PmergeMe &);

		void	sort(void);

	private:
		std::string	str;

		double	sortVector(void);
		void	mergeVector(std::vector<Block<std::vector<int *> > > &);
		void	insertVector(std::vector<Block<std::vector<int *> > > &);
		void	applyInsertVector(std::vector<Block<std::vector<int *> > > &, std::vector<Block<std::vector<int *> > > &);
		double	sortDeque(void);
		void	mergeDeque(std::deque<Block<std::deque<int *> > > &);
		void	insertDeque(std::deque<Block<std::deque<int *> > > &);
		void	applyInsertDeque(std::deque<Block<std::deque<int *> > > &, std::deque<Block<std::deque<int *> > > &);

		class InvalidSyntax : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};


template <typename T>
T	binary_search(T begin, T end, T insert);
int	jacobsthal_number(const int n);

#include "PmergeMe.tpp"

#endif