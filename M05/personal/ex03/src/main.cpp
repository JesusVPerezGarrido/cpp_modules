/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:31:30 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 18:13:20 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	normal_use(void)
{
	std::cerr << "----testing-normal-use----" << std::endl;
	Bureaucrat	ceo_of_man("Mr M. Man", 1);
	Intern 		peter_parker;
	AForm	*tree = peter_parker.makeForm("shrubbery creation", "Home");
	AForm	*obama = peter_parker.makeForm("robotomy request", "Obama");
	AForm	*jhon = peter_parker.makeForm("presidential pardon", "Jhon Cena");

	ceo_of_man.signForm(*tree);
	ceo_of_man.executeForm(*tree);
	ceo_of_man.signForm(*obama);
	ceo_of_man.executeForm(*obama);
	ceo_of_man.signForm(*jhon);
	ceo_of_man.executeForm(*jhon);
	delete tree;
	delete obama;
	delete jhon;
}

void	test_exception(void)
{
	Bureaucrat bond("Bond, James Bond", 1);
	Bureaucrat intern("Intern", 150);
	Intern bruce_wayne;
	AForm	*form;

	std::cerr << "----testing-invalid-form----" << std::endl;
	form = bruce_wayne.makeForm("robo", "Mamaaaa");

	std::cerr << "----testing-unsigned-form----" << std::endl;
	form = bruce_wayne.makeForm("robotomy request", "Mamaaaa");
	intern.executeForm(*form);

	std::cerr << "----testing-forbidden-sign----" << std::endl;
	intern.signForm(*form);

	std::cerr << "----testing-forbidden-execute----" << std::endl;
	bond.signForm(*form);
	intern.executeForm(*form);
	delete form;
}

int	main(void)
{
	normal_use();
	std::cerr << "----testing-exceptions----" << std::endl;
	test_exception();
}