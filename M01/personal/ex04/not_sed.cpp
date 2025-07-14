/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_sed.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:34:08 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/02 11:47:36 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_sed.hpp"

int	NotSed::init(std::string infile, std::string s1, std::string s2)
{
	if (infile.empty() || s1.empty() || s2.empty())
		return (-1);
	_s1 = s1;
	_s2 = s2;
	_infile = infile;
	_outfile = infile.append(".replace");
	_buffer.clear();
	_input.open(_infile.c_str());
	if (!_input.is_open())
	{
		std::cerr << "failed to open file" << std::endl;
		return (-1);
	}
	_output.open(_outfile.c_str());
	if (!_output.is_open())
	{
		std::cerr << "failed to create file" << std::endl;
		return (-1);
	}
	return (0);
}

void	NotSed::end(void)
{
	_infile.clear();
	_outfile.clear();
	_s1.clear();
	_s2.clear();
	_input.close();
	_output.close();
}

void	NotSed::replace(std::string infile, std::string s1, std::string s2)
{
	int	start;
	int	position;

	if (init(infile, s1, s2) == -1)
		return ;
	while (!_input.eof())
	{
		std::getline(_input, _buffer);
		start = 0;
		position = _buffer.find(_s1);
		while (position != -1)
		{
			_buffer.erase(position, s1.length());
			_buffer.insert(position, s2);
			start += position + _s2.length();
			position = _buffer.find(_s1, start);
		}
		_output << _buffer << std::endl;
	}
	end();
}
