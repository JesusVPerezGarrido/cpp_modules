/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:31:30 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 17:34:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	normal_use(void)
{
	std::cerr << "----testing-normal-use----" << std::endl;
	Bureaucrat ceo_of_man("Mr M. Man", 1);
	ShruberryCreationForm	tree("Home");
	RobotomyRequestForm		obama("Obama");
	PresidentialPardonForm		jhon("Jhon Cena");
	ceo_of_man.signForm(tree);
	ceo_of_man.executeForm(tree);
	ceo_of_man.signForm(obama);
	ceo_of_man.executeForm(obama);
	ceo_of_man.signForm(jhon);
	ceo_of_man.executeForm(jhon);
}

void	test_exception(void)
{
	Bureaucrat bond("Bond, James Bond", 1);
	Bureaucrat intern("Intern paid in exposition", 150);
	RobotomyRequestForm	robo("Mamaaaaa");
	std::cerr << "----testing-unsigned-form----" << std::endl;
	intern.executeForm(robo);

	std::cerr << "----testing-forbidden-sign----" << std::endl;
	intern.signForm(robo);

	std::cerr << "----testing-forbidden-execute----" << std::endl;
	bond.signForm(robo);
	intern.executeForm(robo);
}

int	main(void)
{
	normal_use();
	std::cerr << "----testing-exceptions----" << std::endl;
	test_exception();
}