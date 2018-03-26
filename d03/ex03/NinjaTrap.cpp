/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:34:50 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 18:56:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void ): ClapTrap()
{
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
	this->name = "N1NJ4TR4P";
	std::cout << "[NIN]Hahaha minion!! I ascend!!" << std::endl;
}

NinjaTrap::NinjaTrap( std::string const & name ): ClapTrap(name)
{
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
	std::cout << "[NIN]Hahaha minion!! I ascend!!" << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src ): ClapTrap(src)
{
	std::cout << "[NIN]Hahaha minion!! I ascend!!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "[NIN]OOoooh?! Stairs? Nooooooo!!" << std::endl;
}

NinjaTrap &		NinjaTrap::operator=( NinjaTrap const & rhs )
{
	this->hit_points = rhs.hit_points;
	this->max_hit_points = rhs.max_hit_points;
	this->energy_points = rhs.energy_points;
	this->max_energy_points = rhs.max_energy_points;
	this->level = rhs.level;
	this->name = rhs.name;
	this->melee_attack_damage = rhs.melee_attack_damage;
	this->ranged_attack_damage = rhs.ranged_attack_damage;
	this->armor_damage_reduction = rhs.armor_damage_reduction;

	return *this;
}

/*
** Features
*/

void			NinjaTrap::ninjaShoebox( ClapTrap const & target )
{
	if (this->energy_points < 25)
	{
		std::cout << "No enough energy!" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << "<" << target.name << "> recieved ninjutsu attack: " << std::endl;
		std::cout << "\tnin nin: " << this->name << ": ";
		std::cout << "Stairs no JUTSU!" << std::endl;
	}
}

void			NinjaTrap::ninjaShoebox( ScavTrap const & target )
{
	if (this->energy_points < 25)
	{
		std::cout << "No enough energy!" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << "<" << target.name << "> recieved ninjutsu attack: " << std::endl;
		std::cout << "\tnin nin: " << this->name << ": ";
		std::cout << "Scav no JUTSU!" << std::endl;
	}
}

void			NinjaTrap::ninjaShoebox( FragTrap const & target )
{
	if (this->energy_points < 25)
	{
		std::cout << "No enough energy!" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << "<" << target.name << "> recieved ninjutsu attack: " << std::endl;
		std::cout << "\tnin nin: " << this->name << ": ";
		std::cout << "Frag no JUTSU!" << std::endl;
	}
}

void			NinjaTrap::ninjaShoebox( NinjaTrap const & target )
{
	if (this->energy_points < 25)
	{
		std::cout << "No enough energy!" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << "<" << target.name << "> recieved ninjutsu attack: " << std::endl;
		std::cout << "\tnin nin: " << this->name << ": ";
		std::cout << "Git clone no JUTSU!" << std::endl;
	}
}
