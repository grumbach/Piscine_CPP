/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_ufo.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 19:39:03 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_ufo.hpp"

A_ufo::A_ufo( int const velocity, int const skin )
	: pos_x(-1)
	, pos_y(-1)
	, skin(skin)
	, velocity(velocity)
	, _last_move(clock())
{ }

A_ufo::A_ufo( A_ufo const & src )
{
	*this = src;
}

A_ufo::~A_ufo()
{ }


A_ufo &			A_ufo::operator=( A_ufo const & rhs )
{
	if (this != &rhs)
	{
		this->pos_x = rhs.pos_x;
		this->pos_y = rhs.pos_y;
		this->velocity = rhs.velocity;
		this->skin = rhs.skin;
	}
	return (*this);
}


bool			A_ufo::out_of_bounds()
{
	return (this->pos_y > LINES || this->pos_y < 0 || \
			this->pos_x > COLS || this->pos_x < 0);
}

bool			A_ufo::can_move()
{
	clock_t		now = clock();
	double		diffticks = now - this->_last_move;
	double		diffms = diffticks / ( CLOCKS_PER_SEC / 1000 );

	if (diffms < this->velocity)
		return false;

	this->_last_move = now;
	return true;
}
