/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_sed.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/24 19:02:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOT_SED_HPP
# define NOT_SED_HPP

#include <iostream>
#include <fstream>

class NotSed
{
	private:
		std::string		_infile;
		std::string		_outfile;
		std::string		_s1;
		std::string		_s2;
		std::ifstream	_input;
		std::ofstream 	_output;
		std::string		_buffer;
	
		int		init(std::string infile, std::string s1, std::string s2);
		void	end(void);

	public:
		void	replace(std::string infile, std::string s1, std::string s2);
};

#endif
