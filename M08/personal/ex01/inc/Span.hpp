/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:08:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/03 18:26:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <ctime>

class Span
{
	public:
		Span(void);
		Span(const unsigned int &size);
		Span(const Span &copy);
		~Span(void);

		void addNumber(const int &num);
		void populate(void);

		int	shortestSpan(void);
		int	longestSpan(void);

	private:
		std::vector<int>	_container;
		unsigned int		_size;
		unsigned int		_used;

		class FullSpanInsertion : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		class SpanNotBigEnough : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif