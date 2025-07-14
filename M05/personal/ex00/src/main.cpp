/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:31:30 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:45:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	normal_use(void)
{
	std::cerr << "----testing-normal-use----" << std::endl;
	std::cerr << "----creating-bureaucrats----" << std::endl;
	Bureaucrat jhon_smith("Jhon Smith", 1);
	Bureaucrat goon;

	std::cerr << "----getters----" << std::endl;
	std::cout << "names:" << jhon_smith.getName() << ", " << goon.getName() << std::endl;
	std::cout << "grades:" << jhon_smith.getGrade() << ", " << goon.getGrade() << std::endl;

	std::cerr << "----changing-grades----" << std::endl;
	jhon_smith.decrementGrade();
	goon.incrementGrade();
	std::cout << jhon_smith << std::endl << goon << std::endl;
}

void	creation_exceptions(void)
{
	std::cerr << "----creation-exceptions----" << std::endl;
	try
	{
		Bureaucrat mary_sue("Mary Sue", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat slug("slug", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}

void	modification_exceptions(void)
{
	std::cerr << "----modification-exceptions----" << std::endl;
	try
	{
		Bureaucrat stickman("Stickman", 1);
		stickman.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat cat("kittycat", 150);
		cat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	normal_use();
	std::cerr << "----testing-exceptions----" << std::endl;
	creation_exceptions();
	modification_exceptions();
}