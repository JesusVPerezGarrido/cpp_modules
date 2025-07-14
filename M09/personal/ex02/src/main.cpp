/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:44:05 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/14 15:02:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "usage: ./PmergeMe <integer sequence>" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	m(av[1]);
		m.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
}