/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:52:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 13:24:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

Base	*generate(void)
{
	std::time_t t = time(NULL);
	if (t % 3 == 1)
	{
		std::cout << "created A type" << std::endl;
		return (new A());
	}
	else if (t % 3 == 2)
	{
		std::cout << "created B type" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "created C type" << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	std::cout << "pointer identify" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "The type generated is A." << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "The type generated is B." << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "The type generated is C." << std::endl;
}

void	identify(Base &p)
{
	std::cout << "reference identify" << std::endl;
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The type generated is A" << std::endl;
	}
	catch (std::exception e)
	{
		(void)e;
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "The type generated is B" << std::endl;
		}
		catch (std::exception e)
		{
			(void)e;
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "The type generated is C" << std::endl;
			}
			catch(std::exception e)
			{
				(void)e;
			}
		}
	}
}

int	main(void)
{
	Base	*base = generate();

	identify(base);
	identify(*base);
	delete base;
}