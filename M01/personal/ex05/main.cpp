/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:39:27 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/24 19:42:13 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl hl;

	hl.complain("DEBUG");
	hl.complain("INFO");
	hl.complain("WARNING");
	hl.complain("ERROR");
	hl.complain("NONSENSE");
}
