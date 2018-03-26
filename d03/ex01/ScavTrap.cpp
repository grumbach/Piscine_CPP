/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:57 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 17:03:55 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
	: hit_points (100)
	, max_hit_points (100)
	, energy_points (50)
	, max_energy_points (50)
	, level (1)
	, name ("Scavling")
	, melee_attack_damage (20)
	, ranged_attack_damage (15)
	, armor_damage_reduction (3)
{
	std::cout << "Hahaha YYYYYYYYYYaaaa!!!" << std::endl;
}

ScavTrap::ScavTrap( std::string const & name )
	: hit_points (100)
	, max_hit_points (100)
	, energy_points (50)
	, max_energy_points (50)
	, level (1)
	, name (name)
	, melee_attack_damage (20)
	, ranged_attack_damage (15)
	, armor_damage_reduction (3)
{
	std::cout << "Hahaha YYYYYYYYYYaaaa!!!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src )
	: hit_points (src.hit_points)
	, max_hit_points (src.max_hit_points)
	, energy_points (src.energy_points)
	, max_energy_points (src.max_energy_points)
	, level (src.level)
	, name (src.name)
	, melee_attack_damage (src.melee_attack_damage)
	, ranged_attack_damage (src.ranged_attack_damage)
	, armor_damage_reduction (src.armor_damage_reduction)
{
	std::cout << "Hahaha YYYYYYYYYYaaaa!!!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "AAAH AAAHH AAAHH!! I see the liiiggghhtt.." << std::endl;
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

void			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP <" << this->name << "> attacks <" << \
		target << "> at range, causing <" << this->ranged_attack_damage << \
		"> points of damage !" << std::endl;
}

void			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP <" << this->name << "> melee attacks <" << \
		target << ">, causing <" << this->melee_attack_damage << \
		"> points of damage !" << std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage_after_armor;

	if (amount > this->armor_damage_reduction)
		damage_after_armor = amount - this->armor_damage_reduction;
	else
		damage_after_armor = 0;

	if (this->hit_points < damage_after_armor)
		this->hit_points = 0;
	else
		this->hit_points -= damage_after_armor;

	std::cout << "SC4V-TP <" << this->name << "> takes <" << \
		damage_after_armor << "> points of damage !" << \
		" Hit Points are currently at: " << this->hit_points << std::endl;
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	if (amount > this->max_hit_points || \
		this->hit_points + amount > this->max_hit_points)
		this->hit_points = this->max_hit_points;
	else
		this->hit_points += amount;

	std::cout << "SC4V-TP <" << this->name << "> gets a repair of <" << \
		amount << "> Hit Points (currently: " << this->hit_points << \
		")"<< std::endl;
}

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
