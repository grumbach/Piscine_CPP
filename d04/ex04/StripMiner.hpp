/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:03:27 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:11:49 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIPMINER_H
# define STRIPMINER_H

#include <iostream>
#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {

public:

	StripMiner( void );
	~StripMiner();

	StripMiner &		operator=( StripMiner const & rhs );

	virtual void		mine( IAsteroid * a );

};

#endif
