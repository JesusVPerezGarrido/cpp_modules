/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:58:43 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/18 16:33:56 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

# ifndef CONTACT_MAX
#  define CONTACT_MAX 8
# endif

class PhoneBook {
	public:
		void	start(void);
		void	add(void);
		void	search(void);

		PhoneBook(void);
		~PhoneBook(void);

	private:
		Contact	contacts[CONTACT_MAX];
		int		max = 0;
		int		oldest = 0;
};

#endif
