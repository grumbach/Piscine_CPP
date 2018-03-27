/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:44 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:15:34 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

MiningBarge::MiningBarge( void )
{
	int		i = 0;

	while (i < BARGE_CAPACITY)
	{
		this->minerSlot_[i] = NULL;
		i++;
	}
}

MiningBarge::~MiningBarge()
{ }

MiningBarge &				MiningBarge::operator=( MiningBarge const & rhs )
{
	int		i = 0;

	while (i < BARGE_CAPACITY)
	{
		this->minerSlot_[i] = rhs.minerSlot_[i];
		i++;
	}
	return *this;
}

/*
** Features
*/

void 					MiningBarge::equip( IMiningLaser * laser )
{
	int		i = 0;

	while (i < BARGE_CAPACITY)
	{
		if (!this->minerSlot_[i])
		{
			this->minerSlot_[i] = laser;
			break ;
		}
		i++;
	}
}

void					MiningBarge::mine( IAsteroid * a ) const
{
	int		i = 0;

	while (i < BARGE_CAPACITY)
	{
		if (this->minerSlot_[i])
		{
			this->minerSlot_[i]->mine(a);
		}
		i++;
	}
}
