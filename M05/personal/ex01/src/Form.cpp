/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:06:21 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:49:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(void) :
	name("Blank Paper"),
	is_signed(false),
	sign_grade(150),
	exec_grade(150)
{
	std::cerr << "Created: " << *this << std::endl;
}
Form::Form(const std::string &_name, const int &sign, const int &exec) :
	name(_name),
	is_signed(false),
	sign_grade(sign),
	exec_grade(exec)
{
	std::cerr << "Created: " << *this << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) :
	name(copy.name),
	is_signed(copy.is_signed),
	sign_grade(copy.sign_grade),
	exec_grade(copy.exec_grade)
{
	std::cerr << "Created: " << *this << std::endl;
}

// Deconstructors
Form::~Form(void)
{
	std::cerr << "Deleted: " << *this << std::endl;
}

Form	&Form::operator = (const Form &form)
{
	if (this == &form)
		return (*this);
	//can't change other memebers because of constant
	is_signed = form.is_signed;
	return (*this);
}

// Getters
const std::string &Form::getName(void) const
{
	return (name);
}

const bool &Form::getIsSigned(void) const
{
	return (is_signed);
}

const int &Form::getSignGrade() const
{
	return (sign_grade);
}

const int &Form::getExecGrade() const
{
	return (exec_grade);
}

// Methods
void Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > sign_grade)
		throw ForbiddenBureacratSign();
	is_signed = true;
}

// Exceptions
const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low");
}

const char *Form::ForbiddenBureacratSign::what(void) const throw()
{
	return ("Bureaucrat grade too low to sign the form");
}

// Operator overload
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form(name: " << form.getName()
		<< ", signed: " << form.getIsSigned()
		<< ", sign_grade: " << form.getSignGrade()
		<< ", exec_grade: " << form.getExecGrade() << ")";
	return (out);
}