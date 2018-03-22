/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:20:32 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:36:23 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string init_type)
	:type(init_type)
{ }

Weapon::~Weapon ()
{ }

const std::string		&Weapon::getType(void) const
{
	const std::string	&ref = this->type;

	return (ref);
}

void					Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
