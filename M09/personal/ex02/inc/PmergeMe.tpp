/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:39:15 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/16 12:53:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
Block<T>::Block(void) :
	head(),
	container()
{}

template <typename T>
Block<T>::Block(const Block &other) :
	head(other.head),
	container(other.container)
{}

template <typename T>
Block<T>::Block(int &a) :
	head(&a),
	container()
{
	container.push_back(&a);
}

template <typename T>
Block<T>::Block(Block &a, Block &b)
{
	if (a > b)
	{
		int	placeholder;
		typename T::iterator	a_it = a.getContainer().begin();
		typename T::iterator	b_it = b.getContainer().begin();
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

template <typename T>
Block<T>::~Block(void)
{}

template <typename T>
Block<T>	&Block<T>::operator = (const Block &other)
{
	if (this == &other)
		return (*this);
	head = other.head;
	container = other.container;
	return (*this);
}

template <typename T>
bool	Block<T>::operator < (const Block &other) const
{
	return (*head < *other.head);
}

template <typename T>
bool	Block<T>::operator > (const Block &other) const
{
	return (other < *this);
}

template <typename T>
bool	Block<T>::operator == (const Block &other) const
{
	return (*head == *other.head);
}

template <typename T>
int	*Block<T>::getHead()
{
	return (head);
}

template <typename T>
T	&Block<T>::getContainer(void)
{
	return (container);
}

template <typename T>
std::ostream	&operator << (std::ostream &os, Block<T> &obj)
{
	os << "Block(head: " << *obj.getHead();
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

template <typename T>
T	binary_search(T begin, T end, T insert)
{
	while (begin < end)
	{
		T mid = begin + (end - begin) / 2;
		if (*mid < *insert)
			begin = mid + 1;
		else
			end = mid;
	}
	if (*begin < *insert)
		return (begin + 1);
	return (begin);
}