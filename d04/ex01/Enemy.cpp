/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:54:07 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:54:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
	: hp(hp)
	, type(type)
{ }

Enemy::Enemy( Enemy const & src )
	: hp(src.hp)
	, type(src.type)
{ }

Enemy::~Enemy(void)
{ }

std::string Enemy::getType(void) const
{
	return this->type;
}

int Enemy::getHP(void) const
{
	return this->hp;
}

void Enemy::takeDamage(int damage)
{
	if (damage > 0)
		this->hp -= damage;
}
