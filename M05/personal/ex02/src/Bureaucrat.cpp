/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:41:59 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:54:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	name("Nameless"),
	grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &_name, const int &_grade) :
	name(_name),
	grade(_grade)
{
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	name(copy.name),
	grade(copy.grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureau)
{
	if (this == &bureau)
		return (*this);
	//can't change name because of constant
	grade = bureau.grade;
	return (*this);
}

void	Bureaucrat::incrementGrade(void)
{
	grade--;
	checkGrade();
}

void	Bureaucrat::decrementGrade(void)
{
	grade++;
	checkGrade();
}

const std::string	&Bureaucrat::getName(void) const
{
	return (name);
}

const int	&Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() 
			<< " because " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.beExecuted(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't execute " << form.getName() 
			<< " because " << e.what() << '\n';
	}
}

void	Bureaucrat::checkGrade(void)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade too low");
}

std::ostream	&operator << (std::ostream &out, const Bureaucrat &bureau)
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return (out);
}
