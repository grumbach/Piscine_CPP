/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:53:48 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 15:44:27 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( void ) : A_spacecraft(0, PLAYER_SKIN)
{
	this->hp = DEFAULT_HP;
}

Player::Player( Player const & src ) : A_spacecraft(src)
{
	*this = src;
}

Player::~Player()
{
	return ;
}


Player &			Player::operator=( Player const & rhs )
{
	(void)rhs;
	return (*this);
}

void				Player::shoot_missile()
{
	for (size_t i = 0; i < MISSILES; i++)
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

void				Player::move()
{ }
