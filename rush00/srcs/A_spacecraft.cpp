/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_spacecraft.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 15:02:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_spacecraft.hpp"

A_spacecraft::A_spacecraft( int const velocity, int const skin ) : A_ufo(velocity, skin)
{ }

A_spacecraft::A_spacecraft( A_spacecraft const & src ) : A_ufo(src)
{ }

A_spacecraft::~A_spacecraft()
{ }


A_spacecraft &		A_spacecraft::operator=( A_spacecraft const & rhs )
{
	(void)rhs;
	return *this;
}

int					A_spacecraft::take_damage( int const quantity )
{
	if (hp > 0)
		this->hp -= quantity;
	if (this->hp <= 0)
	{
		this->pos_x = -1;
		this->pos_y = -1;
	}
	return quantity;
}

bool				A_spacecraft::check_collision( A_spacecraft *opposing_force, \
					size_t force_size )
{
	for (size_t i = 0; i < force_size; i++)
	{
		if (opposing_force[i].hp > 0)
		{
			if (this->pos_x == opposing_force[i].pos_x && \
				this->pos_y == opposing_force[i].pos_y)
			{
				this->take_damage(1);
				opposing_force[i].take_damage(1);
				return true;
			}
		}
	}
	return false;
}
