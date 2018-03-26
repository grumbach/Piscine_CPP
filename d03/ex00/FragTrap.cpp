/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:55:04 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 15:53:57 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
	: hit_points (100)
	, max_hit_points (100)
	, energy_points (100)
	, max_energy_points (100)
	, level (1)
	, name ("FR4GTR4P")
	, melee_attack_damage (30)
	, ranged_attack_damage (20)
	, armor_damage_reduction (5)
{
	std::cout << "Hahaha minion!! I ascend!!" << std::endl;
}

FragTrap::FragTrap( std::string const & name )
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
	std::cout << "Hahaha minion!! I ascend!!" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src )
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
	std::cout << "Hahaha minion!! I ascend!!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "OOoooh?! Stairs? Nooooooo!!" << std::endl;
}

FragTrap &		FragTrap::operator=( FragTrap const & rhs )
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

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << \
		target << "> at range, causing <" << this->ranged_attack_damage << \
		"> points of damage !" << std::endl;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->name << "> melee attacks <" << \
		target << ">, causing <" << this->melee_attack_damage << \
		"> points of damage !" << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
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

	std::cout << "FR4G-TP <" << this->name << "> takes <" << \
		damage_after_armor << "> points of damage !" << \
		" Hit Points are currently at: " << this->hit_points << std::endl;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if (amount > this->max_hit_points || \
		this->hit_points + amount > this->max_hit_points)
		this->hit_points = 100;
	else
		this->hit_points += amount;

	std::cout << "FR4G-TP <" << this->name << "> gets a repair of <" << \
		amount << "> Hit Points (currently: " << this->hit_points << \
		")"<< std::endl;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	static int			seed = 0;
	if (!seed++)
		std::srand(std::time(nullptr));
	int					rand = std::rand() % 5;
	const std::string	subroutines[5] =
	{
		"Aannnnd Opeeeeen!!",
		"You are cordially invited to my birthday Party!",
		"Doors, I WAS MADE TO OPEN DOORS!!!",
		"High Five!!!",
		"My mighty Minion! Destroy thy master's enemy!"
	};

	std::cout << "<" << target << "> recieved surprise attack: " << std::endl;
	std::cout << "\tsubroutine: " << this->name << ": ";
	std::cout << subroutines[rand] << std::endl;
}
