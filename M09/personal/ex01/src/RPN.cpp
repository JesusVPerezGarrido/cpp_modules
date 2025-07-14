/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:24:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/07 16:48:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN::calculate(std::string exp)
{
	std::stack<int>	container;

	if (exp.empty())
	{
		std::cout << std::endl;
		return ;
	}

	std::string::iterator	it = exp.begin();
	while (it != exp.end())
	{
		if (*it >= '0' && *it <= '9')
			container.push(*it - '0');
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			operate(container, *it);
		else if (!std::isspace(*it))
			throw InvalidCharacterFound();
		it++;
	}
	if (container.size() != 1)
		throw BadInputFound();
	std::cout << container.top() << std::endl;
}

void RPN::operate(std::stack<int> &c, char op)
{
	if (c.size() < 2)
		throw BadInputFound();

	int num2 = c.top();
	c.pop();
	int num1 = c.top();
	c.pop();

	switch (op)
	{
	case '+':
		c.push(num1 + num2);
		break;
	
	case '-':
		c.push(num1 - num2);
		break;

	case '*':
		c.push(num1 * num2);
		break;

	case '/':
		c.push(num1 / num2);
		break;
		
	default:
		throw BadInputFound();
	}
}

const char	*RPN::InvalidCharacterFound::what(void) const throw()
{
	return "Invalid character";
}

const char	*RPN::BadInputFound::what(void) const throw()
{
	return "Invalid syntax";
}