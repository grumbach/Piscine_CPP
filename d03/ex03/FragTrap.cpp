/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:55:04 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 18:56:14 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
	this->name = "FR4GTR4P";
	std::cout << "[FR4G]Hahaha minion!! I ascend!!" << std::endl;
}

FragTrap::FragTrap( std::string const & name ): ClapTrap(name)
{
	std::cout << "[FR4G]Hahaha minion!! I ascend!!" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ): ClapTrap(src)
{
	std::cout << "[FR4G]Hahaha minion!! I ascend!!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FR4G]OOoooh?! Stairs? Nooooooo!!" << std::endl;
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
	if (this->energy_points < 25)
	{
		std::cout << "No enough energy!" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << "<" << target << "> recieved surprise attack: " << std::endl;
		std::cout << "\tsubroutine: " << this->name << ": ";
		std::cout << subroutines[rand] << std::endl;
	}
}
