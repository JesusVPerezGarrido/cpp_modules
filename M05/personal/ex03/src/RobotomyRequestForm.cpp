/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:22:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 15:46:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(const std::string &_target) :
	AForm::AForm("Robotomy Request", 72, 45),
	target(_target)
{

}

// Deconstructors
RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

// Getters
const std::string	&RobotomyRequestForm::getTarget(void)
{
	return (target);
}

// Methods
void	RobotomyRequestForm::execute()
{
	std::cout << "* Loud drilling noises *" << std::endl;
	if (time(NULL) % 2)
		std::cout << "Congratulations " << target << " to your new life as a microwave" << std::endl;
	else
		std::cout << target << " didn't make it. Try again." << std::endl;
}