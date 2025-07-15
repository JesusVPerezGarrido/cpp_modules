/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:37:47 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/15 12:28:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

BlockVector::BlockVector(void) :
	head(),
	container()
{}
BlockVector::BlockVector(const BlockVector &b) :
	head(b.head),
	container(b.container)
{}

BlockVector::BlockVector(const int &first, const int &second)
{
	if (first > second)
	{
		head = first;
		container.push_back(second);
		container.push_back(first);
	}
	else
	{
		head = second;
		container.push_back(first);
		container.push_back(second);
	}
}

BlockVector::BlockVector(const BlockVector &first, const BlockVector &second)
{
	if (first > second)
	{
		head = first.head;
		
		container.insert(container.end(), second.getContainer().begin(), second.getContainer().end());
		container.insert(container.end(), first.getContainer().begin(), first.getContainer().end());
	}
	else
	{
		head = second.head;
		container.insert(container.end(), first.getContainer().begin(), first.getContainer().end());
		container.insert(container.end(), second.getContainer().begin(), second.getContainer().end());
	}
}

BlockVector::~BlockVector(void)
{}

const BlockVector	&BlockVector::operator = (const BlockVector &b)
{
	if (this == &b)
		return (*this);
	head = b.head;
	container = b.container;
	return (*this);
}

const int &BlockVector::getHead(void) const
{
	return (head);
}

const std::vector<int> &BlockVector::getContainer(void) const
{
	return (container);
}

bool	BlockVector::operator < (const BlockVector &b) const
{
	if (head < b.head)
		return (true);
	return (false);
}

bool	BlockVector::operator > (const BlockVector &b) const
{
	return (b < *this);
}

std::ostream	&operator<<(std::ostream &os, const BlockVector &obj)
{
	os << "BlockVector(head: " << obj.getHead() << ", container: {";
	for (std::vector<int>::const_iterator it = obj.getContainer().begin(); it != obj.getContainer().end(); it++)
	{
		os << *it;
		if (it + 1 != obj.getContainer().end())
			os << ", ";
	}
	os << "})";
    return os;
}

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(const std::string &_str) :
	str(_str)
{}

PmergeMe::PmergeMe(const PmergeMe &pmm) :
	str(pmm.str)
{}

PmergeMe::~PmergeMe(void)
{}

const PmergeMe &PmergeMe::operator = (const PmergeMe &pmm)
{
	if (this == &pmm)
		return (*this);
	return (*this);
}

void	PmergeMe::sort(void)
{
	sortVector();
	//sort Deque(void)
}

void PmergeMe::sortVector(void)
{
	std::vector<int> container;

	if (str.find_first_not_of("0123456789 ") != str.npos)
		throw InvalidSyntax();

	std::size_t	index = 0;
	while (index != str.npos)
	{
		int num = std::atoi(str.substr(index).c_str());
		if (num < 0)
			throw InvalidSyntax();
		container.push_back(num);
		index = str.find_first_of(" ", index);
		index = str.find_first_not_of(" ", index);
	}
	mergeVector(container);
}

template <typename T>
void	PmergeMe::mergeVector(std::vector<T> &c)
{
	if (c.size() < 2)
		return ;

	// std::cout << "before merging:";
	// for (typename std::vector<T>::iterator it = c.begin(); it != c.end(); it++)
	// 	std::cout << " " << *it;
	// std::cout << std::endl;

	std::vector<BlockVector> blocks;
	for (std::size_t i = 0; i + 1 < c.size(); i += 2)
		blocks.push_back(BlockVector(c[i], c[i + 1]));

	std::cout << "after merging:";
	for (typename std::vector<BlockVector>::iterator it = blocks.begin(); it != blocks.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	mergeVector(blocks);
	if (blocks.size() > 3)
		insertVector(blocks);
	std::cout << "ending depth" << std::endl;
}

template <typename T>
void	PmergeMe::insertVector(std::vector<T> c)
{
	std::vector<T>	main;
	std::vector<T>	pend;
	
	main.push_back(c[0]);
	main.push_back(c[1]);
	for (std::size_t i = 2; i < c.size(); i++)
	{
		if (i % 2)
			pend.push_back(c[i]);
		else
			main.push_back(c[i]);
	}
	
}

const char	*PmergeMe::InvalidSyntax::what(void) const throw()
{
	return ("Invalid input syntax");
}