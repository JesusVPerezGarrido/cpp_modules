/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:21:35 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/25 10:48:39 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Megaphone
{
	public:
		static void	estatic(void)
		{
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		}
		
		static void	loud(char *str)
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

	if (ac == 1)
		Megaphone::estatic();
	else
	{
		index = 1;
		while (av[index])
		{
			Megaphone::loud(av[index]);
			if (index + 1 != ac)
				std::cout << " ";
			index++;
		}
	}
	std::cout << std::endl;
}
