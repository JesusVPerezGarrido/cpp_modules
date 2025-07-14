/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:31:30 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 13:43:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	normal_use(void)
{
	std::cerr << "----testing-normal-use----" << std::endl;
	std::cerr << "----creating-bureaucrats----" << std::endl;
	Bureaucrat jhon_smith("Jhon Smith", 1);
	Bureaucrat goon;

	std::cerr << "----bureaucrats-getters----" << std::endl;
	std::cout << "names: " << jhon_smith.getName() << ", " << goon.getName() << std::endl;
	std::cout << "grades: " << jhon_smith.getGrade() << ", " << goon.getGrade() << std::endl;

	std::cerr << "----changing-grades----" << std::endl;
	jhon_smith.decrementGrade();
	goon.incrementGrade();
	std::cout << jhon_smith << std::endl << goon << std::endl;

	std::cerr << "----creating-forms----" << std::endl;
	Form contract("Film Contract", 3, 3);
	Form plans;
	
	std::cerr << "----form-getters----" << std::endl;
	std::cout << "names: " << contract.getName() << ", " << plans.getName() << std::endl;
	std::cout << "is signed: " << contract.getIsSigned() << ", " << plans.getIsSigned() << std::endl;
	std::cout << "sign grade: " << contract.getSignGrade() << ", " << plans.getSignGrade() << std::endl;
	std::cout << "exec grade: " << contract.getExecGrade() << ", " << plans.getExecGrade() << std::endl;

	std::cerr << "----signing-forms----" << std::endl;
	jhon_smith.signForm(contract);
	goon.signForm(plans);
}

void	creation_exceptions(void)
{
	std::cerr << "----bureaucrats-creation-exceptions----" << std::endl;
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
	std::cerr << "----forms-creation-exceptions----" << std::endl;
	try
	{
		Form evil_plans("Evil Plans", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form survey("survey", 151, 151);
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
	std::cerr << "----sign-exceptions----" << std::endl;
	try
	{
		Bureaucrat	villain_lackey("Villain's lackey", 10);
		Form permit("Cat Petting Permit", 1, 1);
		villain_lackey.signForm(permit);
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