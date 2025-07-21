/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:20:41 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/21 16:27:08 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>
#include <exception>

class RPN
{
	public:
		static void	calculate(std::string exp);

	private:
		RPN(void);
		RPN(const RPN &rpn);
		~RPN(void);

		const RPN	&operator = (const RPN &rpn);

		static void operate(std::stack<int> &c, char op);

		class InvalidCharacterFound : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class BadInputFound : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class InvalidOperation : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif