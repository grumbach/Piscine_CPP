/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:47:06 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:47:29 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
	: name(name)
	, apcost(apcost)
	, damage(damage)
{ }

AWeapon::AWeapon( AWeapon const & src )
	: name(src.name)
	, apcost(src.apcost)
	, damage(src.damage)
{ }

AWeapon::~AWeapon()
{ }

std::string		AWeapon::getName() const
{
	return this->name;
}

int				AWeapon::getAPCost() const
{
	return this->apcost;
}

int				AWeapon::getDamage() const
{
	return this->damage;
}
