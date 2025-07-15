/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:37:47 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/15 17:59:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

BlockVector::BlockVector(void) :
	head(),
	container()
{}

BlockVector::BlockVector(const BlockVector &other) :
	head(other.head),
	container(other.container)
{}

BlockVector::BlockVector(int &a) :
	head(&a),
	container()
{
	container.push_back(&a);
}

BlockVector::BlockVector(BlockVector &a, BlockVector &b)
{
	if (a > b)
	{
		int	placeholder;
		std::vector<int	*>::iterator	a_it = a.getContainer().begin();
		std::vector<int	*>::iterator	b_it = b.getContainer().begin();
		while (a_it != a.getContainer().end() && b_it != b.getContainer().end())
		{
			placeholder = **a_it;
			**a_it = **b_it;
			**b_it = placeholder;
			a_it++;
			b_it++;
		}
	}
	head = b.getHead();
	container.insert(container.end(), a.getContainer().begin(), a.getContainer().end());
	container.insert(container.end(), b.getContainer().begin(), b.getContainer().end());
	
}

BlockVector::~BlockVector(void)
{}

BlockVector	&BlockVector::operator = (const BlockVector &other)
{
	if (this == &other)
		return (*this);
	head = other.head;
	container = other.container;
	return (*this);
}

bool	BlockVector::operator < (const BlockVector &other) const
{
	return (*head < *other.head);
}

bool	BlockVector::operator > (const BlockVector &other) const
{
	return (other < *this);
}

bool	BlockVector::operator == (const BlockVector &other) const
{
	return (*head == *other.head);
}

int *BlockVector::getHead()
{
	return (head);
}

std::vector<int *> &BlockVector::getContainer(void)
{
	return (container);
}

std::ostream &operator << (std::ostream &os, BlockVector &obj)
{
	os << "BlockVector(head: " << *obj.getHead();
	//os << "(" << obj.getHead() << ")";
	os << ", blocks: {";
	for (std::vector<int *>::iterator it = obj.getContainer().begin(); it != obj.getContainer().end(); it++)
	{
		os << **it;
		//os << "(" << *it << ")";
		if (it + 1 != obj.getContainer().end())
			os << ", ";
	}
	os << "})";
	return os;
}

PmergeMe::PmergeMe(void) {}

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
	str = pmm.str;
	return (*this);
}

void	PmergeMe::sort(void)
{
	sortVector();
}

void PmergeMe::sortVector(void)
{
	std::vector<int>	array;
	std::vector<BlockVector> blocks;
	std::istringstream iss(str);
	int num;

	while (iss >> num)
	{
		if (num < 0)
			throw InvalidSyntax();
		array.push_back(num);
	}
	
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		blocks.push_back(*it);
	if (blocks.empty())
		throw InvalidSyntax();

	mergeVector(blocks);

	std::cout << "result:";
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		std::cout << " " <<*it;
	std::cout << std::endl;
}

void PmergeMe::mergeVector(std::vector<BlockVector> &c)
{
	if (c.size() < 2)
		return;

	std::cout << "----[entered merge]----" << std::endl;

	// std::cout << "* before merging:";
	// for (std::vector<BlockVector>::iterator it = c.begin(); it != c.end(); it++)
	// 	std::cout << " " << *it;
	// std::cout << std::endl;

	std::vector<BlockVector> blocks;
	for (std::size_t i = 0; i + 1 < c.size(); i += 2)
	{
		BlockVector b(c[i], c[i + 1]);
		blocks.push_back(b);
	}
	std::cout << "----[ending merge]----" << std::endl;

	// std::cout << "* after merging:";
	// for (std::vector<BlockVector>::iterator it = blocks.begin(); it != blocks.end(); it++)
	// 	std::cout << " " << *it;
	// std::cout << std::endl;

	if (blocks.size() > 1)
		mergeVector(blocks);
	if (c.size() > 2)
		insertVector(c);
	
	//apply changes
}

void PmergeMe::insertVector(std::vector<BlockVector> &c)
{
	std::cout << "----[entered insert]----" << std::endl;
	std::vector<BlockVector> main;
	std::vector<BlockVector> pend;

	main.push_back(c[0]);
	main.push_back(c[1]);
	for (std::size_t i = 2; i < c.size(); i++)
	{
		if (i % 2)
			main.push_back(c[i]);
		else
			pend.push_back(c[i]);
	}

	std::cout << "* main:";
	for (std::vector<BlockVector>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;

	std::cout << "* pend:";
	for (std::vector<BlockVector>::iterator it = pend.begin(); it != pend.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;

	int	jacob_it = 2;
	int	prev_jacobsthal = jacobsthal_number(jacob_it++);
	int	cur_jacobsthal = jacobsthal_number(jacob_it++);
	while (cur_jacobsthal - prev_jacobsthal <= static_cast<int>(pend.size()))
	{
		int	jacob_diff = cur_jacobsthal - prev_jacobsthal;
		while (jacob_diff--)
		{
			BlockVector insert = *(pend.begin() + jacob_diff);
			//std::cout << "* inserting: " << insert << std::endl;
			pend.erase(pend.begin() + jacob_diff);
			std::vector<BlockVector>::iterator insert_pos = binary_search(main.begin(), main.begin() + prev_jacobsthal + 1, pend.begin() + jacob_diff);
			//std::cout << "* insert position: " << *insert_pos << std::endl;
			main.insert(insert_pos, insert);
		}
		prev_jacobsthal = cur_jacobsthal;
		cur_jacobsthal = jacobsthal_number(jacob_it++);
		break ;
	}

	std::cout << "* c:";
	for (std::vector<BlockVector>::iterator it = c.begin(); it != c.end(); ++it)
	std::cout << " " << *it;
	std::cout << std::endl;

	std::cout << "* main:";
	for (std::vector<BlockVector>::iterator it = main.begin(); it != main.end(); ++it)
	std::cout << " " << *it;
	std::cout << std::endl;


	applyInsertVector(c, main);

	std::cout << "* result:";
	for (std::vector<BlockVector>::iterator it = c.begin(); it != c.end(); ++it)
	std::cout << " " << *it;
	std::cout << std::endl;
	
	std::cout << "----[ending insert]----" << std::endl;
}

void	PmergeMe::applyInsertVector(std::vector<BlockVector> &dst, std::vector<BlockVector> &src)
{
	std::vector<int> placeholder;

	std::vector<BlockVector>::iterator s_it = src.begin();
	while (s_it != src.end())
	{
		std::vector<int *>::iterator sn_it = s_it->getContainer().begin();
		while (sn_it != s_it->getContainer().end())
		{
			placeholder.push_back(**sn_it);
			sn_it++;
		}
		s_it++;
	}
	
	std::vector<BlockVector>::iterator d_it = dst.begin();
	while (d_it != dst.end())
	{
		std::vector<int *>::iterator dn_it = d_it->getContainer().begin();
		while (dn_it != d_it->getContainer().end())
		{
			**dn_it = placeholder.front();
			placeholder.erase(placeholder.begin());
			dn_it++;
		}
		d_it++;
	}
}

const char	*PmergeMe::InvalidSyntax::what(void) const throw()
{
	return ("Invalid input syntax");
}

int	jacobsthal_number(const int n)
{
	if (n < 1)
		return (0);
	if (n < 3)
		return (1);
	return (2 * jacobsthal_number(n - 2) + jacobsthal_number(n - 1));
}