/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:21:35 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/12 12:30:04 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Megaphone
{
	public:
		void	estatic(void)
		{
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		}
		
		void	loud(char *str)
		{
			int	index;
			
			index = 0;
			while (str[index])
			{
				std::cout << (char)toupper(str[index]);
				index++;
			}
		}
};

int	main(int ac, char **av)
{
	int			index;
	Megaphone	mp;

	if (ac == 1)
		mp.estatic();
	else
	{
		index = 1;
		while (av[index])
		{
			mp.loud(av[index]);
			if (index + 1 != ac)
				std::cout << " ";
			index++;
		}
	}
	std::cout << std::endl;
}
