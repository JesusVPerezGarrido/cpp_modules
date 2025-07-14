/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:45:22 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 18:13:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern(void)
{}

Intern	&Intern::operator = (const Intern &intern)
{
	(void)intern;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &str, const std::string &target)
{
	try
	{
		AForm	*form;
		switch (stringToFormId(str))
		{
			case 0:
				form = new ShruberryCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			default:
				throw InternFormNotFound();
		}
		std::cout << "Intern created " << form->getName() << std::endl;
		return (form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Intern couldn't create the form " << str << " because " << e.what() << std::endl;
		return (NULL);
	}
}

int	Intern::stringToFormId(const std::string &str)
{
	std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
		if (forms[i] == str)
			return (i);
	return (-1);
}

const char	*Intern::InternFormNotFound::what(void) const throw()
{
	return ("Intern used chatgpt for his degree");
}