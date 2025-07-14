/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:34:29 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/21 13:20:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
 	std::cout << "[[Creating Objects...]]" << std::endl;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	std::cout << "[[Testing basic materia learning...]]" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "[[Testing basic materia equipment...]]" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("asd");
	me->equip(tmp);

	std::cout << "[[Testing use of materials]]" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-1, *bob);
	me->use(4, *bob);

	std::cout << "[[Testing overflow materia equipment...]]" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << "[[Testing removed Materia use]]" << std::endl;
	me->unequip(-1);
	me->unequip(0);
	me->unequip(4);
	me->use(0, *bob);

	std::cout << "[[Deleting objects...]]" << std::endl;
	delete me;
	delete bob;
	delete src;
	std::cout << "[[Testing Deep Copy...]]" << std::endl;
	Character test("me");
	{
		Character chara = test;
	}
}
