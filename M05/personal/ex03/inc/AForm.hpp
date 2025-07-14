/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:52:56 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:55:23 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm(void);
		AForm(const std::string &, const int &, const int &);
		AForm(const AForm &);

		// Deconstructors
		virtual ~AForm(void);

		// Operators
		AForm	&operator = (const AForm &form);

		// Setters

		// Getters
			const std::string	&getName() const;
			const bool			&getIsSigned() const;
			const int			&getSignGrade() const;
			const int			&getExecGrade() const;


		// Methods
		void			canBeExecutedBy(const Bureaucrat &);
		void			beSigned(const Bureaucrat &);
		void			beExecuted(const Bureaucrat &);
		virtual void	execute() =0;

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
		class ForbiddenBureaucratSign : public std::exception 
		{
			public:
				const char	*what(void) const throw();
		};
		class ForbiddenBureaucratExecute : public std::exception 
		{
			public:
				const char	*what(void) const throw();
		};
		class ExecuteUnsignedForm : public std::exception 
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator << (std::ostream &, const AForm &);

#endif