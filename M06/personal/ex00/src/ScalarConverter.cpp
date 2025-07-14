/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:30:19 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 12:20:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter(void)
{}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &scalar)
{
	(void)scalar;
	return (*this);
}

void ScalarConverter::convert (std::string str)
{
	std::cout << "convert input: \"" << str << "\"" << std::endl;
	// trim any whitespace after or before input
	trimString(str);

	// if string is empty default to 0
	if (str.empty())
	{
		std::cout << "char: undisplayable" << std::endl
			<< "int: 0" << std::endl
			<< "float: 0.0f" << std::endl
			<< "double: 0.0" << std::endl;
		return;
		convertChar(str);
	}

	// Rredirect to each type
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
			convertChar(str);
	else if (str.find('.') == str.npos && str.find("inf") == str.npos && str.find("nan") == str.npos)
			convertInt(str);
	else if (str.find('f') != str.npos && !(str.find("inf") != str.npos && str.find("inff") == str.npos))
			convertFloat(str);
	else
			convertDouble(str);

}

void ScalarConverter::trimString(std::string &str)
{
	if (str.find_first_not_of(WHITESPACE_CSTR) == str.npos)
	{
		str.clear();
		return ;
	}
	str.substr(str.find_first_not_of(WHITESPACE_CSTR));
	str.substr(0, str.find_last_not_of(WHITESPACE_CSTR));
}

void ScalarConverter::convertChar(const std::string &str)
{
	char	c;
	int		i;
	float	f;
	double	d;

	c = static_cast<char>(str[1]);
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertInt(const std::string &str)
{
	int		c;
	long	i;
	float	f;
	double	d;

	i = static_cast<long>(std::atol(str.c_str()));
	c = static_cast<int>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertFloat(const std::string &str)
{
	int		c;
	long	i;
	float	f;
	double	d;

	f = static_cast<float>(std::atof(str.c_str()));
	c = static_cast<int>(f);
	i = static_cast<long>(f);
	d = static_cast<double>(f);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertDouble(const std::string &str)
{
	int		c;
	long	i;
	float	f;
	double	d;

	d = static_cast<double>(std::atof(str.c_str()));
	c = static_cast<int>(d);
	i = static_cast<long>(d);
	f = static_cast<float>(d);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void	ScalarConverter::printChar(const int &c)
{
	std::cout << "char: ";
	if (c < 0 || c > 127)
		std::cout << "impossible";
	else if (std::isprint(c))
		std::cout << static_cast<char>(c);
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	ScalarConverter::printInt(const int &i)
{
	std::cout << "int: ";
	if (i < -2147483648 || i > 2147483647)
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}

void	ScalarConverter::printFloat(const float &f)
{
	std::cout << "float: " << f;
	if (std::isfinite(f) && std::floor(f) == std::ceil(f))
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
}

void	ScalarConverter::printDouble(const double &d)
{
	std::cout << "double: " << d;
	if (std::isfinite(d) && std::floor(d) == std::ceil(d))
		std::cout << ".0";
	std::cout << std::endl;
}