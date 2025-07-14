/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:17:01 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/25 15:36:33 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(int ac, char **av)
{
	NotSed not_sed;

	if (ac != 4)
	{
		std::cerr << "Usage: not_sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	not_sed.replace(av[1], av[2], av[3]);

}
