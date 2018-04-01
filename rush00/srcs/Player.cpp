/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:53:48 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 19:07:34 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( void ) : A_spacecraft(0, PLAYER_SKIN)
{
	this->hp = DEFAULT_HP;
}

Player::Player( Player const & src ) : A_spacecraft(src)
{ }

Player::~Player()
{ }


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

void				Player::apply_input( int const ch )
{
	if (ch == this->_binding_down && this->pos_y < LINES - 1)
		this->pos_y++;
	else if (ch == this->_binding_up && this->pos_y > 1)
		this->pos_y--;
	else if (ch == this->_binding_left && this->pos_x > 0)
		this->pos_x--;
	else if (ch == this->_binding_right && this->pos_x < COLS - 1)
		this->pos_x++;
	else if (ch == this->_binding_shoot)
		this->shoot_missile();
}

void				Player::set_bindings( int d, int u, int l, int r, int s )
{
	this->_binding_down = d;
	this->_binding_up = u;
	this->_binding_left = l;
	this->_binding_right = r;
	this->_binding_shoot = s;
}

/*

  ^
/<|>\
  ^

*/
