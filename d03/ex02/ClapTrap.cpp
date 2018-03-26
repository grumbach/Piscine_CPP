/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:06:15 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 18:24:33 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
	: hit_points (100)
	, max_hit_points (100)
	, energy_points (100)
	, max_energy_points (100)
	, level (1)
	, name ("CL4PTR4P")
	, melee_attack_damage (30)
	, ranged_attack_damage (20)
	, armor_damage_reduction (5)
{
	std::cout << "[CL4P]Hahaha minion!! I ascend!!" << std::endl;
}

ClapTrap::ClapTrap( std::string const & name )
	: hit_points (100)
	, max_hit_points (100)
	, energy_points (100)
	, max_energy_points (100)
	, level (1)
	, name (name)
	, melee_attack_damage (30)
	, ranged_attack_damage (20)
	, armor_damage_reduction (5)
{
	std::cout << "[CL4P]Hahaha minion!! I ascend!!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src )
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
	std::cout << "[CL4P]Hahaha minion!! I ascend!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[CL4P]OOoooh?! Stairs? Nooooooo!!" << std::endl;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const & rhs )
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

void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CL4P-TP <" << this->name << "> attacks <" << \
		target << "> at range, causing <" << this->ranged_attack_damage << \
		"> points of damage !" << std::endl;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP <" << this->name << "> melee attacks <" << \
		target << ">, causing <" << this->melee_attack_damage << \
		"> points of damage !" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
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

	std::cout << "CL4P-TP <" << this->name << "> takes <" << \
		damage_after_armor << "> points of damage !" << \
		" Hit Points are currently at: " << this->hit_points << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > this->max_hit_points || \
		this->hit_points + amount > this->max_hit_points)
		this->hit_points = this->max_hit_points;
	else
		this->hit_points += amount;

	std::cout << "CL4P-TP <" << this->name << "> gets a repair of <" << \
		amount << "> Hit Points (currently: " << this->hit_points << \
		")"<< std::endl;
}
