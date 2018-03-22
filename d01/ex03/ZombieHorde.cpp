/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:32:28 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 03:31:35 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(unsigned int horde_size)
	: horde_size(horde_size)
{
	std::string	names[6] = {"tutu", "titi", "toto", "tata", "tete", "tyty"};
	std::string	type = "horde";

	std::srand(std::time(nullptr));
	this->zombies = new Zombie[horde_size];
	for (size_t i = 0; i < horde_size; i++)
	{
		this->zombies[i].type = type;
		this->zombies[i].name = names[std::rand() % 6];
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->zombies;
}

void			ZombieHorde::announce()
{
	for (size_t i = 0; i < this->horde_size; i++)
	{
		this->zombies[i].announce();
	}
}
