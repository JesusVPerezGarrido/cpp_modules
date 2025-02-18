/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:07:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/18 14:20:01 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::~Contact(void)
{
}

void	Contact::set(void)
{
	std::cout << "-[ Contact Information ]-" << std::endl;
	set_field("First Name: ", &first_name);
	set_field("Last Name: ", &last_name);
	set_field("Nickname: ", &nickname);
	set_field("Phone Number: ", &phone_number);
	set_field("Darkest Secret: ", &darkest_secret);
	if (!std::cin.eof())
		std::cout << "-[ Contact Added ]-" << std::endl;
}

void	Contact::brief(void)
{
	brief_string(first_name, '|');
	brief_string(last_name, '|');
	brief_string(nickname, '\n');
}

void	Contact::full(void)
{
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}

void	Contact::set_field(std::string prompt, std::string *field)
{
	while (field->empty() && !std::cin.eof())
	{
		std::cout << prompt;
		std::getline(std::cin, *field);
	}
}


void	Contact::brief_string(std::string str, char tail)
{
	int	length;

	length = str.length();
	if (length > 10)
		std::cout << str.substr(0, 9) << "." << tail;
	else
	{
		for (int i = 0; i < 10 - length; i++)
			std::cout << " ";
		std::cout << str << tail;
	}
}
