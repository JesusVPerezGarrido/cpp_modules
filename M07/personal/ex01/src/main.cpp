/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:28:38 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/01 16:53:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void add_one(int &i)
{
	i += 1;
}

void print_int(const int &i)
{
	std::cout << " " << i;
}

int main(void)
{
	const std::size_t size = 5;
	
	int *arr = new int[size];
	for (std::size_t i = 0; i < size; i++)
		arr[i] = i + 1;

	std::cout << "arr:";
	iter(arr, size, print_int);
	std::cout << std::endl;

	iter(arr, size, add_one);
	
	std::cout << "arr:";
	iter(arr, size, print_int);
	std::cout << std::endl;
}