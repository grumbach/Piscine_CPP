/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy_missile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:07:24 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 19:41:15 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy_missile.hpp"

Enemy_missile::Enemy_missile( void ) : Missile(MISSILES_DELAY, EMISSILES_SKIN)
{
	this->hp = 0;
}

Enemy_missile::Enemy_missile( Enemy_missile const & src ) : Missile(src)
{ }

Enemy_missile::~Enemy_missile()
{ }


Enemy_missile &			Enemy_missile::operator=( Enemy_missile const & rhs )
{
	(void)rhs;
	return *this;
}

void					Enemy_missile::move()
{
	if (this->out_of_bounds())
	{
		this->pos_y = -1;
		this->pos_x = -1;
		this->hp = 0;
	}

	if (this->hp && this->can_move())
		this->pos_y++;
}
