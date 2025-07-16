/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:37:47 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/16 13:01:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac == 1)
		str = av[1];
	else
	{
		for (int i = 1; i < ac; i++)
		{
			str += av[i];
			if (i != ac)
				str += " ";
		}
	}
	if (str.find_first_not_of("0123456789 ") != str.npos)
		throw InvalidSyntax();
}

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
	std::cout << "[*] input: " << str << std::endl;
	double	vector_time;
	double	deque_time;
	vector_time = sortVector();
	deque_time = sortDeque();
	std::cout << "[*] vector_time: " << vector_time << "s" << std::endl;
	std::cout << "[*] deque_time: " << deque_time << "s" << std::endl;
}

double PmergeMe::sortVector(void)
{
	clock_t	start;
	clock_t	end;
	std::vector<int>	array;
	std::vector<Block<std::vector<int *> > > blocks;
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

	start = clock();
	mergeVector(blocks);
	end = clock();

	std::cout << "[*] output:";
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
}

void PmergeMe::mergeVector(std::vector<Block<std::vector<int *> > > &c)
{
	if (c.size() < 2)
		return;

	std::vector<Block<std::vector<int *> > > blocks;
	for (std::size_t i = 0; i + 1 < c.size(); i += 2)
	{
		Block<std::vector<int *> > b(c[i], c[i + 1]);
		blocks.push_back(b);
	}

	if (blocks.size() > 1)
		mergeVector(blocks);
	if (c.size() > 2)
		insertVector(c);
}

void PmergeMe::insertVector(std::vector<Block<std::vector<int *> > > &c)
{
	std::vector<Block<std::vector<int *> > > main;
	std::vector<Block<std::vector<int *> > > pend;
	main.push_back(c[0]);
	main.push_back(c[1]);
	for (std::size_t i = 2; i < c.size(); i++)
	{
		if (i % 2)
			main.push_back(c[i]);
		else
			pend.push_back(c[i]);
	}

	int	jacob_it = 2;
	int	prev_jacobsthal = jacobsthal_number(jacob_it++);
	int	cur_jacobsthal = jacobsthal_number(jacob_it++);
	int	search_size = 3;
	while (cur_jacobsthal - prev_jacobsthal <= static_cast<int>(pend.size()))
	{
		int	jacob_diff = cur_jacobsthal - prev_jacobsthal;
		while (jacob_diff--)
		{
			std::vector<Block<std::vector<int *> > >::iterator insert = pend.begin() + jacob_diff;
			std::vector<Block<std::vector<int *> > >::iterator insert_pos = binary_search(main.begin(), main.begin() + search_size - 1, insert);
			main.insert(insert_pos, *insert);
			pend.erase(pend.begin() + jacob_diff);
		}
		search_size += cur_jacobsthal + ( cur_jacobsthal - prev_jacobsthal);
		prev_jacobsthal = cur_jacobsthal;
		cur_jacobsthal = jacobsthal_number(jacob_it++);
	}

	search_size = main.size();
	while (pend.size())
	{
		std::vector<Block<std::vector<int *> > >::iterator insert = pend.end() - 1;
		std::vector<Block<std::vector<int *> > >::iterator insert_pos = binary_search(main.begin(), main.begin() + search_size - 1, insert);
		main.insert(insert_pos, *insert);
		pend.erase(pend.end() - 1);
	}

	applyInsertVector(c, main);
}

void	PmergeMe::applyInsertVector(std::vector<Block<std::vector<int *> > > &dst, std::vector<Block<std::vector<int *> > > &src)
{
	std::vector<int> placeholder;

	std::vector<Block<std::vector<int *> > >::iterator s_it = src.begin();
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
	
	std::vector<Block<std::vector<int *> > >::iterator d_it = dst.begin();
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

double PmergeMe::sortDeque(void)
{
	clock_t	start;
	clock_t	end;
	std::deque<int>	array;
	std::deque<Block<std::deque<int *> > > blocks;
	std::istringstream iss(str);
	int num;

	while (iss >> num)
	{
		if (num < 0)
			throw InvalidSyntax();
		array.push_back(num);
	}
	
	for (std::deque<int>::iterator it = array.begin(); it != array.end(); it++)
		blocks.push_back(*it);
	if (blocks.empty())
		throw InvalidSyntax();

	start = clock();
	mergeDeque(blocks);
	end = clock();

	return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
}

void PmergeMe::mergeDeque(std::deque<Block<std::deque<int *> > > &c)
{
	if (c.size() < 2)
		return;

	std::deque<Block<std::deque<int *> > > blocks;
	for (std::size_t i = 0; i + 1 < c.size(); i += 2)
	{
		Block<std::deque<int *> >  b(c[i], c[i + 1]);
		blocks.push_back(b);
	}

	if (blocks.size() > 1)
		mergeDeque(blocks);
	if (c.size() > 2)
		insertDeque(c);
}

void PmergeMe::insertDeque(std::deque<Block<std::deque<int *> > > &c)
{
	std::deque<Block<std::deque<int *> > > main;
	std::deque<Block<std::deque<int *> > > pend;
	main.push_back(c[0]);
	main.push_back(c[1]);
	for (std::size_t i = 2; i < c.size(); i++)
	{
		if (i % 2)
			main.push_back(c[i]);
		else
			pend.push_back(c[i]);
	}

	int	jacob_it = 2;
	int	prev_jacobsthal = jacobsthal_number(jacob_it++);
	int	cur_jacobsthal = jacobsthal_number(jacob_it++);
	int	search_size = 3;
	while (cur_jacobsthal - prev_jacobsthal <= static_cast<int>(pend.size()))
	{
		int	jacob_diff = cur_jacobsthal - prev_jacobsthal;
		while (jacob_diff--)
		{
			std::deque<Block<std::deque<int *> > >::iterator insert = pend.begin() + jacob_diff;
			std::deque<Block<std::deque<int *> > >::iterator insert_pos = binary_search(main.begin(), main.begin() + search_size - 1, insert);
			main.insert(insert_pos, *insert);
			pend.erase(pend.begin() + jacob_diff);
		}
		search_size += cur_jacobsthal + ( cur_jacobsthal - prev_jacobsthal);
		prev_jacobsthal = cur_jacobsthal;
		cur_jacobsthal = jacobsthal_number(jacob_it++);
	}

	search_size = main.size();
	while (pend.size())
	{
		std::deque<Block<std::deque<int *> > >::iterator insert = pend.end() - 1;
		std::deque<Block<std::deque<int *> > >::iterator insert_pos = binary_search(main.begin(), main.begin() + search_size - 1, insert);
		main.insert(insert_pos, *insert);
		pend.erase(pend.end() - 1);
	}

	applyInsertDeque(c, main);
}

void	PmergeMe::applyInsertDeque(std::deque<Block<std::deque<int *> > > &dst, std::deque<Block<std::deque<int *> > > &src)
{
	std::deque<int> placeholder;

	std::deque<Block<std::deque<int *> > >::iterator s_it = src.begin();
	while (s_it != src.end())
	{
		std::deque<int *>::iterator sn_it = s_it->getContainer().begin();
		while (sn_it != s_it->getContainer().end())
		{
			placeholder.push_back(**sn_it);
			sn_it++;
		}
		s_it++;
	}
	
	std::deque<Block<std::deque<int *> > >::iterator d_it = dst.begin();
	while (d_it != dst.end())
	{
		std::deque<int *>::iterator dn_it = d_it->getContainer().begin();
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