/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:54:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 15:57:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include "AForm.hpp"
# include <ctime>

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors
		PresidentialPardonForm(const std::string &target);

		// Deconstructors
		~PresidentialPardonForm(void);

		// Getters
		const std::string &getTarget(void);

		// Methods
		void	execute();

	private:
		const std::string	target;
};

#endif