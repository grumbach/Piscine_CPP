/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy_boss.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:48:47 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 20:50:44 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy_boss.hpp"

Enemy_boss::Enemy_boss( void ) : Enemy(ENEMIES_DELAY, ENEMIES_SKIN)
{
	this->_spawn_delay = RANDOM_SPAWN_DELAY;
}

Enemy_boss::Enemy_boss( Enemy_boss const & src ) : A_spacecraft(src)
{
	*this = src;
}

Enemy_boss::~Enemy_boss()
{ }


Enemy_boss &			Enemy_boss::operator=( Enemy_boss const & rhs )
{
	(void)rhs;
	return *this;
}

void			Enemy_boss::move()
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
		this->_spawn_delay = RANDOM_SPAWN_DELAY;
	}
}

void			Enemy_boss::_shoot_missile()
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
