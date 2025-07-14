/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:40:16 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 17:50:35 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>
# include <exception>

class Intern
{
	public:
		// Constructors
		Intern(void);
		Intern(const Intern &copy);

		// Deconstructors
		~Intern(void);

		// Operators
		Intern	&operator = (const Intern &intern);

		// Methods
		AForm	*makeForm(const std::string &, const std::string &);

	private:
		// Methods
		int	stringToFormId(const std::string &);

		// Exceptions
		class InternFormNotFound : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif