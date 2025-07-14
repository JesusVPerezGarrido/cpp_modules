/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:56:48 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/07 15:52:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc) :
	container(btc.container)
{}

BitcoinExchange::~BitcoinExchange(void)
{}

const BitcoinExchange	&BitcoinExchange::operator = (const BitcoinExchange &btc)
{
	if (this == &btc)
		return (*this);
	container = btc.container;
	return (*this);
}

void	BitcoinExchange::parseDatabase(void)
{
	std::ifstream	file;
	std::string		buf;

	if (!container.empty())
		container.clear();

	file.open(DEFAULT_DATABASE);
	if (!file.is_open())
		throw FileNotFound();

	bool	first_flag = true;
	while (!file.eof())
	{
		std::getline(file, buf);
		if (buf.empty())
			continue ;

		if (buf.find(',') == buf.npos)
		{
			if (first_flag)
			{
				first_flag = false;
				continue;
			}
			else
				throw InvalidSyntax();
		}

		std::string	date = buf.substr(0, buf.find(','));
		std::string	value = buf.substr(buf.find(',') + 1).c_str();

		if (date.find_first_not_of("0123456789-") != buf.npos)
		{
			if (first_flag)
			{
				first_flag = false;
				continue;
			}
			else
				throw InvalidSyntax();
		}
		if (value.find_first_not_of("0123456789.") != buf.npos)
		{
			if (first_flag)
			{
				first_flag = false;
				continue;
			}
			else
				throw InvalidSyntax();
		}

		first_flag = false;
		container[date] = std::atof(value.c_str());
	}
}

void	BitcoinExchange::calculateValue(std::string inputfile)
{
	std::ifstream	file;
	std::string		buf;

	file.open(inputfile.c_str());
	if (!file.is_open())
		throw FileNotFound();

	while (!file.eof())
	{
		std::getline(file, buf);
		if (buf.empty())
			continue ;
		if (buf.find('|') == buf.npos)
		{
			std::cout << "Error: bad input => " << buf << std::endl;
			continue ;
		}

		std::string	date = buf.substr(0, buf.find('|'));
		std::string	amount = buf.substr(buf.find('|') + 1);
		trim_whitespace(date);
		trim_whitespace(amount);

		if (!validDate(date) || !validAmount(amount))
			continue ;

		std::map<std::string, double>::iterator entry = container.lower_bound(date);
		
		if (entry != container.begin() && entry->first != date)
			entry--;
		if (entry->first > date)
		{
			std::cout << "Date not found => " << date << std::endl;
			continue ;
		}

		std::cout << date << " => " << amount << " * " << entry->second << "(" << entry->first << ") = " << std::atof(amount.c_str()) * entry->second << std::endl;
	}
}

bool	BitcoinExchange::validDate(const std::string str)
{
	std::size_t it = 0;
	while (it < str.length())
	{
		if (((it == 4 || it == 7) && str[it] != '-') ||
			((it != 4 && it != 7) && (str[it] < '0' || str[it] > '9')))
		{
			std::cout << "Error: invalid syntax => " << str << std::endl;
			return (false);
		}

		it++;
	}
	int year = std::atoi(str.substr(0, 4).c_str());
	int month = std::atoi(str.substr(6, 2).c_str());
	int day = std::atoi(str.substr(9, 2).c_str());
	
	if (month > 12)
	{
		std::cout << "Error: invalid month => " << str << std::endl;
		return (false);
	}
	
	int	days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0))
		days[2]++;
	if (day > days[month])
	{
		std::cout << "Error: invalid day => " << str << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::validAmount(const std::string str)
{
	if (str.find_first_not_of("0123456789.-") != str.npos)
	{
		std::cout << "Error: invalid character => " << str << std::endl;
		return (false);
	}
	double	num	= std::atof(str.c_str());
	if (num < 0)
	{
		std::cout << "Error: value not positive => " << str << std::endl;
		return (false);
	}
	if (num > 1000)
	{
		std::cout << "Error: value too big => " << str << std::endl;
		return (false);
	}
	return (true);
}

void trim_whitespace(std::string &str)
{
	std::size_t	tmp;

	tmp = str.find_first_not_of(" \r\t\f\v\n");
	if (tmp != str.npos)
		str.erase(0, tmp);
	tmp = str.find_last_not_of(" \r\t\f\v\n");
	if (tmp != str.npos)
		str.erase(tmp + 1);
}
const char	*BitcoinExchange::FileNotFound::what(void) const throw()
{
	return ("File not found.");
}
const char	*BitcoinExchange::InvalidSyntax::what(void) const throw()
{
	return ("Invalid syntax found.");
}