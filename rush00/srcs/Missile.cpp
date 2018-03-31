/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:51:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:37:13 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile( void ) : A_spacecraft(MISSILES_VELOCITY, MISSILES_SKIN)
{
	this->hp = 0;
	return ;
}

Missile::Missile( Missile const & src ) : A_spacecraft(src)
{
	*this = src;
}

Missile::~Missile()
{
	return ;
}


Missile &			Missile::operator=( Missile const & rhs )
{
	return *this;
}

void				Missile::move()
{
	//TODO clock with velocity
	if (this->out_of_bounds())
	{
		this->pos_y = -1;
		this->pos_x = -1;
		this->hp = 0;
	}

	if (this->hp)
		this->pos_y--;
}
