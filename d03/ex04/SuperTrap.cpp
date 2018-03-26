/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:03:21 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 10:20:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap( void ): FragTrap(), NinjaTrap()
{
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->name = "SuperTramp";
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 20;
	this->armor_damage_reduction = 5;

	std::cout << "[SUPER]Its morning again!!" << std::endl;
}

SuperTrap::SuperTrap( std::string const & name ): FragTrap(name), NinjaTrap(name)
{
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 20;
	this->armor_damage_reduction = 5;
	this->name = name;

	std::cout << "[SUPER]Its morning again!!" << std::endl;
}

SuperTrap::SuperTrap( SuperTrap const & src ): FragTrap(src), NinjaTrap(src)
{
	std::cout << "[SUPER]Its morning again!!" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "[SUPER]Oooooh nooo its raining again!!" << std::endl;
}

SuperTrap &		SuperTrap::operator=( SuperTrap const & rhs )
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
