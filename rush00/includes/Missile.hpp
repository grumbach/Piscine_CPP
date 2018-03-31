/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:15:59 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 19:28:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H
# define MISSILE_H

#include "A_spacecraft.hpp"

class Missile : public A_spacecraft {

public:

	Missile( void );
	Missile( int const velocity, int const skin );
	Missile( Missile const & src );
	~Missile();

	Missile &		operator=( Missile const & rhs );

	virtual void	move();

};

#endif
