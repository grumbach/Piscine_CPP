/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:54:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:18:15 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : A_spacecraft(ENEMIES_VELOCITY, ENEMIES_SKIN)
{ }

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

	if (this->hp)
		this->pos_y++;
	else
	{
		this->pos_y = 0;
		this->pos_x = RANDOM_SPAWN;
	}
}