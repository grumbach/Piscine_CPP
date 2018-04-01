/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:51:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 19:04:53 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bonus.hpp"

Bonus::Bonus( void ) : A_spacecraft(BONUS_DELAY, BONUS_SKIN)
{
	this->hp = 0;
	this->_spawn_delay = BONUS_SPAWN_DELAY;

}

Bonus::Bonus( Bonus const & src ) : A_spacecraft(src)
{ }

Bonus::~Bonus()
{ }


Bonus &			Bonus::operator=( Bonus const & rhs )
{
	(void)rhs;
	return *this;
}

void				Bonus::check_collision( Player & player )
{
	if (this->pos_x == player.pos_x && \
		this->pos_y == player.pos_y)
	{
		this->take_damage(1);
		player.take_damage(-1);
	}
}

void				Bonus::move()
{
	if (this->_spawn_delay < 0 && out_of_bounds())
		this->hp = 0;
	if (this->hp)
	{
		if (this->can_move() && --this->_spawn_delay < 0)
		{
			this->pos_y++;
		}
	}
	else
	{
		this->hp = 1;
		this->pos_y = -1;
		this->pos_x = RANDOM_X_SPAWN;
		this->_spawn_delay = BONUS_SPAWN_DELAY;
	}
}
