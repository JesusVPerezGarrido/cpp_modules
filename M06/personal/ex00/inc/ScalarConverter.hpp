/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:30:15 by jeperez-          #+#    #+#             */
/*   Updated: 2025/06/30 12:13:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <cmath>

# define WHITESPACE_CSTR " \r\t\f\v\n"

class ScalarConverter
{
	public:
		static void convert(std::string str);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		virtual ~ScalarConverter(void);

		ScalarConverter	&operator = (const ScalarConverter &scalar);

		static void		convertChar(const std::string &str);
		static void		convertInt(const std::string &str);
		static void		convertFloat(const std::string &str);
		static void		convertDouble(const std::string &str);
		static void		printChar(const int &c);
		static void		printInt(const int &i);
		static void		printFloat(const float &f);
		static void		printDouble(const double &d);
		static void		trimString(std::string &str);
};

#endif