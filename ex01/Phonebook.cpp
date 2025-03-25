/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:58:00 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/25 10:53:28 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	max = 0;
	oldest = 0;
}

PhoneBook::~PhoneBook(void)
{}

void	PhoneBook::start(void)
{
	std::string str;

	while (!std::cin.eof())
	{
		std::cout << "enter a command: ";
		std::getline(std::cin, str);
		if (!str.compare("ADD"))
			add();
		else if (!str.compare("SEARCH"))
			search();
		else if (!str.compare("EXIT"))
			break ;
	}
	if (std::cin.eof())
		std::cout << std::endl << "-[ EOF detected, terminating. ]-" << std::endl;
}

void	PhoneBook::search()
{
	int	index;
	std::string	option;

	index = 0;
	std::cout << "-[ Contact Search ]-" << std::endl;
	std::cout << "     index|first_name| last_name|  nickname" << std::endl;
	while (index < max)
	{
		std::cout << "         " << index + 1 << "|";
		contacts[index].brief();
		index++;
	}
	while (true)
	{
		std::cout << "select index (or q to quit):" << std::endl;
		std::getline(std::cin, option);
		if (std::cin.eof())
			break ;
		if (!option.compare("q"))
			break ;
		if (stoi(option) > max || stoi(option) <= 0)
			std::cout << "Option out of bounds." << std::endl;
		else
		{
			contacts[stoi(option) - 1].full();
			break ;
		}
	}
}

void	PhoneBook::add(void)
{
	contacts[oldest].set();
	oldest++;
	if (oldest > max)
		max = oldest;
	if (oldest == CONTACT_MAX)
		oldest = 0;
}
