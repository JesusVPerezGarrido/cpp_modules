/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:33:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/27 11:37:56 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		// Constructor
		Bureaucrat(void);
		Bureaucrat(const std::string &_name, const int &_grade);
		Bureaucrat(const Bureaucrat &copy);

		// Deconstructors
		~Bureaucrat(void);

		// Operators
		Bureaucrat &operator = (const Bureaucrat &bureau);

		// Setters
		void	incrementGrade(void);
		void	decrementGrade(void);

		// Getters
		const std::string	&getName(void) const;
		const int			&getGrade(void) const;

	private:
		// Members
		const std::string	name;
		int					grade;

		// Methods
		void checkGrade(void);

		// Exceptions
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
};

std::ostream	&operator << (std::ostream &out, const Bureaucrat &bureau);

#endif