/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:37:47 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/14 12:29:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::sort(std::string str)
{
	sortVector(str);
	//sortDeque(str);
}

void PmergeMe::sortVector(const std::string &str)
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
	mergeInsertVector(container, 1);
}

void	PmergeMe::mergeInsertVector(std::vector<int> &c, int depth)
{
	const int	num_pairs = c.size() / depth;

	if (num_pairs < 2)
		return ;

	std::cout << "----[start d"<<depth<<"]----" <<std::endl;
	std::cout << "before merging: " <<std::endl;
	for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	for (std::size_t i = 0; (2 * depth) + i - 1 < c.size(); i += 2 * depth)
	{
		//std::cout << "comparing numbers: " << c[depth + i - 1] << "(" << depth + i - 1 << ") and " << c[2 * depth + i - 1] << "(" << 2 * depth + i - 1 << ")" << std::endl;
		if (c[depth + i - 1] > c[(2 * depth) + i - 1])
		{
			//std::cout << "swapping: [" << i << ","<< i + depth - 1 << "] and ["<< depth + i << ","<< 2 * depth + i - 1 << "]" << std::endl;
			for (int j = 0; j < depth; j++)
			{
				int ph = c[i + j];
				c[i + j] = c[depth + i + j];
				c[depth + i + j] = ph;
			}
		}
	}
	std::cout << "after merging: " <<std::endl;
	for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl << std::endl;

	mergeInsertVector(c, 2 * depth);

	if (num_pairs > 4)
	{
		std::vector<int>	main;
		std::vector<int>	pend;
		std::vector<int>	non_part;
		
		main.insert(main.end(), c.begin(), c.begin() + depth);
		main.insert(main.end(), c.begin() + depth, c.begin() + (2 * depth));


		
		for (int i = 4; i <= num_pairs; i += 2)
		{
			main.insert(main.end(), c.begin() + ((i - 1) * depth), c.begin() + (i * depth));
			pend.insert(pend.end(), c.begin() + ((i - 2) * depth), c.begin() + ((i - 1) * depth));
		}

		if ((num_pairs) % 2 == 1)
			pend.insert(pend.end(), c.begin() + ((num_pairs - 1) * depth), c.begin() + (num_pairs * depth));
			
		if (c.size() % depth)
			non_part.insert(non_part.end(), c.begin() + (num_pairs * depth), c.end());

		std::cout << "main: ";
		for (std::vector<int>:: iterator it = main.begin(); it != main.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;
		std::cout << "pend: ";
		for (std::vector<int>:: iterator it = pend.begin(); it != pend.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;
		std::cout << "non_part: ";
		for (std::vector<int>:: iterator it = non_part.begin(); it != non_part.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;

		int jacob_it = 2;
		int	prev_jacob = JacobsthalNumber(jacob_it++);
		int	cur_jacob = JacobsthalNumber(jacob_it++);
		int	jacob_diff = cur_jacob - prev_jacob;
		while (jacob_diff <= static_cast<int>(pend.size() / depth))
		{
			while (jacob_diff)
			{				
				if (jacob_diff > static_cast<int>(pend.size() / depth))
					break;
				std::vector<int>::iterator	insert = pend.begin() + (depth * jacob_diff) - 1;
				std::vector<int>::iterator	cur_chk = main.begin() + depth * std::ceil(cur_jacob / (float)2) - 1;
				int	move = cur_jacob / 2;

				std::cout << "inserting: " << *insert << std::endl;
				while (move)
				{
					std::cout << "comparing: " << *insert << " and " << *cur_chk << std::endl;
					if (*cur_chk < *insert)
					{
						std::cout << "current bigger" << std::endl;
						cur_chk += depth * move;
					}
					else
					{
						std::cout << "current smaller" << std::endl;
						cur_chk -= depth * move;
					}
					move /= 2;
				}

				std::cout << "comparing: " << *insert << " and " << *cur_chk << std::endl;
				if (*cur_chk < *insert)
				{
					main.insert(cur_chk + 1, insert - (depth - 1), insert + 1);
					pend.erase(insert - (depth - 1), insert + 1);
					std::cout << "current bigger" << std::endl;
				}
				else
				{
					main.insert(cur_chk - (depth - 1), insert - (depth - 1), insert + 1);
					pend.erase(insert - (depth - 1), insert + 1);
					std::cout << "current smaller" << std::endl;
				}
			
				std::cout << "main: ";
				for (std::vector<int>:: iterator it = main.begin(); it != main.end(); it++)
					std::cout << " " << *it;
				std::cout << std::endl;
				std::cout << "pend: ";
				for (std::vector<int>:: iterator it = pend.begin(); it != pend.end(); it++)
					std::cout << " " << *it;
				std::cout << std::endl;
				jacob_diff--;
			}
			std::cout << std::endl;
			
			prev_jacob = cur_jacob;
			cur_jacob = JacobsthalNumber(jacob_it++);
			jacob_diff = cur_jacob - prev_jacob;
		}

		c = main;
		c.insert(c.end(), non_part.begin(), non_part.end());
		std::cout << "after inserting: " <<std::endl;
		for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;
	}
	std::cout << "----[end d"<<depth<<"]----" << std::endl << std::endl;
}

template <typename T>
typename T::iterator binarySearch(typename T::iterator begin, typename T::iterator end, typename T::iterator insert)
{
	while (begin != end)
	{
		int	dist = std::distance(begin, end) / 2;
		if (*insert > *(begin + dist))
			begin += dist;
		else
			end -= dist;
	}
	return (begin);
}

int	PmergeMe::JacobsthalNumber(int n)
{
	if (n < 1)
		return (0);
	if (n < 2)
		return (1);
	return ((2 * JacobsthalNumber(n - 2)) + JacobsthalNumber(n - 1));
}

const char	*PmergeMe::InvalidSyntax::what(void) const throw()
{
	return ("Invalid input syntax");
}