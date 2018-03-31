/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:54:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 16:50:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : A_spacecraft(ENEMIES_DELAY, ENEMIES_SKIN)
{
	this->_spawn_delay = RANDOM_SPAWN_DELAY;
}

Enemy::Enemy( Enemy const & src ) : A_spacecraft(src)
{
	*this = src;
}

Enemy::~Enemy()
{
	return ;
}


Enemy &			Enemy::operator=( Enemy const & rhs )
{
	return *this;
}

void			Enemy::move()
{
	//TODO clock velocity

	if (this->_spawn_delay < 0 && out_of_bounds())
		this->hp = 0;
	if (this->hp)
	{
		if (this->can_move() && --this->_spawn_delay < 0)
			this->pos_y++;
	}
	else
	{
		this->hp = 1;
		this->pos_y = -1;
		this->pos_x = RANDOM_X_SPAWN;
		this->_spawn_delay = RANDOM_SPAWN_DELAY;
	}
}
