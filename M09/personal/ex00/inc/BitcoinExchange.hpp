/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:25:51 by jeperez-          #+#    #+#             */
/*   Updated: 2025/07/07 15:33:22 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# ifndef DEFAULT_DATABASE
#  define DEFAULT_DATABASE "data.csv"
# endif

# include <exception>
# include <cstdlib>
# include <fstream>
# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &btc);
		~BitcoinExchange(void);

		const BitcoinExchange	&operator = (const BitcoinExchange &btc);

		void	parseDatabase(void);
		void	calculateValue(std::string	input);

	private:
		std::map<std::string, double>	container;

		bool	validDate(const std::string);
		bool	validAmount(const std::string);

		class FileNotFound : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class InvalidSyntax : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

void trim_whitespace(std::string &);

#endif