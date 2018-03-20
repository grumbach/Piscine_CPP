/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:28:29 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/21 20:26:19 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string default_type)
	: ZombieType(default_type)
{ }

ZombieEvent::~ZombieEvent()
{ }

void			ZombieEvent::setZombieType(std::string type)
{
	this->ZombieType = type;
}

Zombie*			ZombieEvent::newZombie(std::string name)
{
	Zombie		*zombie = new Zombie(this->ZombieType, name);

	return(zombie);
}
