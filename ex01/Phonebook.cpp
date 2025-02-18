/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:58:00 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/18 14:14:09 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	PhoneBook::start(void)
{
	std::string str;

	while (true && !std::cin.eof())
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
	std::cout << "     index|first_name| last_name| nickname" << std::endl;
	while (index < max)
	{
		std::cout << "         " << index + 1 << "|";
		contacts[index].brief();
		index++;
	}
	while (true && !std::cin.eof())
	{
		std::cout << "select index (or q to quit):" << std::endl;
		std::getline(std::cin, option);
		if (!option.compare("q"))
			break ;
		if (atoi(option.c_str()) >= max + 1)
			std::cout << "Option out of bounds." << std::endl;
		if (atoi(option.c_str()) > 0)
		{
			contacts[atoi(option.c_str()) - 1].full();
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
