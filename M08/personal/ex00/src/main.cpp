/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:52:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/03 15:03:20 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	std::cout << "vector contains: " << std::endl;
	std::cout << *easyfind(vec, 1) << std::endl;
	std::cout << *easyfind(vec, 3) << std::endl;
	std::cout << *easyfind(vec, 5) << std::endl;
	
	std::cout << "vector does not contain: " << std::endl;
	try
	{
	std::cout << *easyfind(vec, 25) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}