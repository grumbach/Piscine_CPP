/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:51:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 11:59:18 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile( void ) : A_spacecraft(MISSILES_DELAY, MISSILES_SKIN)
{
	this->hp = 0;
	this->direction = PLAYER_DIRECTION;
}

Missile::Missile( Missile const & src ) : A_spacecraft(src)
{ }

Missile::~Missile()
{ }


Missile &			Missile::operator=( Missile const & rhs )
{
	(void)rhs;
	return *this;
}

void				Missile::move()
{
	if (this->out_of_bounds())
	{
		this->pos_y = -1;
		this->pos_x = -1;
		this->hp = 0;
	}

	if (this->hp && this->can_move())
		this->pos_y += this->direction;
}
