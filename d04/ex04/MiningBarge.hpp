/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:27:43 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:14:51 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MININGBARGE_H
# define MININGBARGE_H

#include <iostream>
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

# define BARGE_CAPACITY			4

class MiningBarge {

public:

	MiningBarge( void );
	~MiningBarge();

	MiningBarge &		operator=( MiningBarge const & rhs );

	void	equip( IMiningLaser * laser );
	void	mine( IAsteroid * a ) const;

	IMiningLaser *			minerSlot_[BARGE_CAPACITY];
};

#endif
