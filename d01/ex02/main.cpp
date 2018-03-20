/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:28:15 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/21 20:27:36 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

Zombie			*randomChump(ZombieEvent	&evt)
{
	int			rand = std::rand();
	std::string	names[6] = {"tutu", "titi", "toto", "tata", "tete", "tyty"};

	Zombie		*zombie = evt.newZombie(names[rand % 6]);
	zombie->announce();
	return (zombie);
}

int				main(void)
{
	std::srand(std::time(nullptr));
	ZombieEvent	evt("undead");

	Zombie		*zombie = randomChump(evt);
	evt.setZombieType("not dead yet");
	Zombie		*zombie2 = randomChump(evt);

	delete zombie;
	delete zombie2;
	return (0);
}
