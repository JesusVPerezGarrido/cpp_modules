/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:06:21 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:51:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
AForm::AForm(void) :
	name("Blank Paper"),
	is_signed(false),
	sign_grade(150),
	exec_grade(150)
{
}
AForm::AForm(const std::string &_name, const int &sign, const int &exec) :
	name(_name),
	is_signed(false),
	sign_grade(sign),
	exec_grade(exec)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) :
	name(copy.name),
	is_signed(copy.is_signed),
	sign_grade(copy.sign_grade),
	exec_grade(copy.exec_grade)
{
}

// Deconstructors
AForm::~AForm(void)
{
}

AForm	&AForm::operator = (const AForm &form)
{
	if (this == &form)
		return (*this);
	//can't change other memebers because of constant
	is_signed = form.is_signed;
	return (*this);
}

// Getters
const std::string	&AForm::getName(void) const
{
	return (name);
}

const bool	&AForm::getIsSigned(void) const
{
	return (is_signed);
}

const int	&AForm::getSignGrade() const
{
	return (sign_grade);
}

const int	&AForm::getExecGrade() const
{
	return (exec_grade);
}

void	AForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > sign_grade)
		throw ForbiddenBureaucratSign();
	is_signed = true;
}

void	AForm::beExecuted(const Bureaucrat &bureau)
{
	if (!getIsSigned())
		throw ExecuteUnsignedForm();
	if (bureau.getGrade() > exec_grade)
		throw ForbiddenBureaucratExecute();
	execute();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low");
}

const char	*AForm::ForbiddenBureaucratSign::what(void) const throw()
{
	return ("Bureaucrat grade too low to sign the Form");
}

const char	*AForm::ForbiddenBureaucratExecute::what(void) const throw()
{
	return ("Bureaucrat grade too low to execute the Form");
}

const char	*AForm::ExecuteUnsignedForm::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream	&operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm(name: " << AForm.getName()
		<< ", signed: " << AForm.getIsSigned()
		<< ", sign_grade: " << AForm.getSignGrade()
		<< ", exec_grade: " << AForm.getExecGrade() << ")";
	return (out);
}