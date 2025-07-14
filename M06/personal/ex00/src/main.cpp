/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:37:31 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 12:18:08 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	tests(void)
{
	// Char tests
	std::cout << "]----char-tests----[" << std::endl;
	ScalarConverter::convert("'a'");
	ScalarConverter::convert("'b'");
	ScalarConverter::convert("'c'");

	// Int tests
	std::cout << "]----int-tests----[" << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-42");

	// Float tests
	std::cout << "]----float-tests----[" << std::endl;
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("4.2f");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("nanf");

	// Double tests
	std::cout << "]----double-tests----[" << std::endl;
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("4.2");
	ScalarConverter::convert("-4.2");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("nan");

	// Char tests
	std::cout << "]----error-tests----[" << std::endl;
	ScalarConverter::convert("");
	ScalarConverter::convert("     	 	 	 	");
	ScalarConverter::convert("asdasdasdasd");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		tests();
	else
		ScalarConverter::convert(argv[1]);
}