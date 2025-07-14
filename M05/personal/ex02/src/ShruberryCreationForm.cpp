/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:22:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/26 15:48:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

// Constructors
ShruberryCreationForm::ShruberryCreationForm(const std::string &_target) :
	AForm::AForm("Shruberry Creation", 145, 137),
	target(_target)
{

}

// Deconstructors
ShruberryCreationForm::~ShruberryCreationForm(void)
{

}

// Getters
const std::string	&ShruberryCreationForm::getTarget(void)
{
	return (target);
}

// Methods
void	ShruberryCreationForm::execute()
{
	std::ofstream	file((target + "_shrubbery").c_str());

	file << "               ,@@@@@@@, \n";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "       |o|        | |         | |\n";
	file << "       |.|        | |         | |\n";
	file << "     \\/ ._\\//_/__/  ,\\_//__\\ /.  \\_//__/_\n";
}