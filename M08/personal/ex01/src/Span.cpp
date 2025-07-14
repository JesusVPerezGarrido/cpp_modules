/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:15:19 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/03 18:26:53 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) :
	_container(),
	_size(0),
	_used(0)
{}

Span::Span(const unsigned int &size) :
	_container(),
	_size(size),
	_used(0)
{}

Span::Span(const Span &copy) :
	_container(),
	_size(copy._size),
	_used(copy._used)
{
	for (unsigned int i = 0; i < _used; i++)
		_container[i] = copy._container[i];
}

Span::~Span(void)
{}

void	Span::addNumber(const int &num)
{
	if (_used > _size)
		throw	FullSpanInsertion();
	_container.push_back(num);
	_used++;
}

void	Span::populate(void)
{
	srand(time(NULL));
	while (_used < _size)
		addNumber(rand());
}

int	Span::shortestSpan(void)
{
	if (_container.size() < 2)
		throw SpanNotBigEnough();
    std::sort(_container.begin(), _container.end());
	int	shortest = _container[1] - _container[0];
	for (std::vector<int>::iterator it = _container.begin(); it + 1 != _container.end(); it++)
	{
		if ((*(it + 1) - *it) < shortest)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}

int	Span::longestSpan(void)
{
	if (_container.size() < 2)
		throw SpanNotBigEnough();
	return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
}

const char	*Span::FullSpanInsertion::what(void) const throw()
{
	return ("Span is full");
}

const char	*Span::SpanNotBigEnough::what(void) const throw()
{
	return ("Span has less than 2 numbers");
}