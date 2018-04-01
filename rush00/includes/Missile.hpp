/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:15:59 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H
# define MISSILE_H

#include "A_spacecraft.hpp"

class Missile : public A_spacecraft {

public:

	Missile( void );
	Missile( Missile const & src );
	virtual ~Missile();

	Missile &		operator=( Missile const & rhs );

	virtual void	move();

	int				direction;	//1 enemy, -1 player

};

#endif
