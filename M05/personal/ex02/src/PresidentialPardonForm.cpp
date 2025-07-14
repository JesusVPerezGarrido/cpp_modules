/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:22:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 15:46:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(const std::string &_target) :
	AForm::AForm("Presidential Pardon", 72, 45),
	target(_target)
{

}

// Deconstructors
PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

// Getters
const std::string	&PresidentialPardonForm::getTarget(void)
{
	return (target);
}

// Methods
void	PresidentialPardonForm::execute()
{
	std::cout << target << " has been pardoned for all their crimes against the rules of phisics by SpongeBob" << std::endl;
}