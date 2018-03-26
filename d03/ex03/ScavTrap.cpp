/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:57 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 18:56:44 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap()
{
	this->name = "Scavling";
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;
	std::cout << "[SCAV]Hahaha YYYYYYYYYYaaaa!!!" << std::endl;
}

ScavTrap::ScavTrap( std::string const & name ): ClapTrap(name)
{
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;
	std::cout << "[SCAV]Hahaha YYYYYYYYYYaaaa!!!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ): ClapTrap(src)
{
	std::cout << "[SCAV]Hahaha YYYYYYYYYYaaaa!!!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[SCAV]AAAH AAAHH AAAHH!! I see the liiiggghhtt.." << std::endl;
}

ScavTrap &		ScavTrap::operator=( ScavTrap const & rhs )
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

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	static int			seed = 0;
	if (!seed++)
		std::srand(std::time(nullptr));
	int					rand = std::rand() % 5;
	const std::string	subroutines[5] =
	{
		"Get a blackhole!",
		"Backup the Blockchain forget your private key!",
		"Ain't level 3 yet?",
		"Ain't getting no xp on your Facebook wall bro!",
		"Get a cold coffee!"
	};

	if (this->energy_points < 25)
	{
		std::cout << "No enough energy!" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << "<" << target << "> recieved taunt: " << std::endl;
		std::cout << "\tilliterate prose: " << this->name << ": ";
		std::cout << subroutines[rand] << std::endl;
	}
}
