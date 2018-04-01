/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:54:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 12:09:04 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : A_spacecraft(ENEMIES_DELAY, ENEMIES_SKIN)
{
	this->_spawn_delay = ENEMY_SPAWN_DELAY;
	for (size_t i = 0; i < ENEMIES_MISSILES; i++)
	{
		this->missiles[i].direction = ENEMIES_DIRECTION;
		this->missiles[i].skin = EMISSILES_SKIN;
	}
}

Enemy::Enemy( Enemy const & src ) : A_spacecraft(src)
{
	*this = src;
}

Enemy::~Enemy()
{ }


Enemy &			Enemy::operator=( Enemy const & rhs )
{
	(void)rhs;
	return *this;
}

void			Enemy::move()
{
	if (this->_spawn_delay < 0 && out_of_bounds())
		this->hp = 0;
	if (this->hp)
	{
		if (this->can_move() && --this->_spawn_delay < 0)
		{
			this->pos_y++;
			if (!(std::rand() % ENEMIES_RANK))
				this->_shoot_missile();
		}
	}
	else
	{
		this->hp = 1;
		this->pos_y = -1;
		this->pos_x = RANDOM_X_SPAWN;
		this->_spawn_delay = ENEMY_SPAWN_DELAY;
	}
}

void			Enemy::_shoot_missile()
{
	for (size_t i = 0; i < ENEMIES_MISSILES; i++)
	{
		if (this->missiles[i].hp == 0)
		{
			this->missiles[i].hp = 1;
			this->missiles[i].pos_y = this->pos_y;
			this->missiles[i].pos_x = this->pos_x;
			break;
		}
	}
}
