/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:54:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 15:55:27 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors
		RobotomyRequestForm(const std::string &target);

		// Deconstructors
		~RobotomyRequestForm(void);

		// Getters
		const std::string &getTarget(void);

		// Methods
		void	execute();

	private:
		const std::string	target;
};

#endif