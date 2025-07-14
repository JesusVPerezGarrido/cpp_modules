/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:52:56 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:46:37 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(void);
		Form(const std::string &, const int &, const int &);
		Form(const Form &);

		// Deconstructors
		~Form(void);

		// Operators
		Form	&operator = (const Form &form);

		// Setters

		// Getters
			const std::string	&getName() const;
			const bool			&getIsSigned() const;
			const int			&getSignGrade() const;
			const int			&getExecGrade() const;


		// Methods
		void	beSigned(const Bureaucrat &);

	private:
		// Members
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;

		//Exceptions
		class GradeTooHighException : public std::exception 
		{
			public:
				const char	*what(void) const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char	*what(void) const throw();
		};
		class ForbiddenBureacratSign : public std::exception 
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator << (std::ostream &, const Form &);

#endif