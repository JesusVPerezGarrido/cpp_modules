/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:20:38 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/04 12:55:46 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <iostream>

void mutantstack_test(void)
{
	std::cout << "----mutant-stack-test----" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

void vector_test(void)
{
	std::cout << "----vector-test----" << std::endl;
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(17);

	std::cout << vec.back() << std::endl;

	vec.pop_back();

	std::cout << vec.size() << std::endl;

	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	//[...]
	vec.push_back(0);

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::vector<int> s(vec);
}

int main(void)
{
	std::cout << "----mutant-stack-test----" << std::endl;
	mutantstack_test();
	vector_test();
	return (0);
}