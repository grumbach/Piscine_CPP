/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:40:46 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 10:42:59 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon)
	: name(name)
	, weapon(weapon)
{ }

HumanA::~HumanA ()
{ }

void			HumanA::attack() const
{
	std::cout << this->name << " attacks with his ";
	std::cout << this->weapon.getType() << std::endl;
}
