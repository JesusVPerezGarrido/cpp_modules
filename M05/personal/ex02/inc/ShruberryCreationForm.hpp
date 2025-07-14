/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:54:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 15:44:16 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
	public:
		// Constructors
		ShruberryCreationForm(const std::string &target);

		// Deconstructors
		~ShruberryCreationForm(void);

		// Getters
		const std::string &getTarget(void);

		// Methods
		void	execute();

	private:
		const std::string	target;
};

#endif