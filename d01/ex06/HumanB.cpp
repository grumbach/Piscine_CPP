/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:01:10 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 10:45:00 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name)
	: name(name)
	, weapon(NULL)
{ }

HumanB::~HumanB ()
{ }

void			HumanB::attack() const
{
	std::cout << this->name << " attacks with his ";
	if (this->weapon)
		std::cout << this->weapon->getType() << std::endl;
	else
		std::cout << "unweaponed fists!" << std::endl;
}

void			HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}
