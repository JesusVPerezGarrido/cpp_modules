/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:13:30 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/03 18:27:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span s(10000);

	s.populate();
	std::cout << "longest span: " << s.longestSpan() << std::endl;
	std::cout << "shortest span: " << s.shortestSpan() << std::endl;
}