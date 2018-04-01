/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_spacecraft.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:55:41 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:49:28 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_SPACECRAFT_H
# define A_SPACECRAFT_H

#include "A_ufo.hpp"

class A_spacecraft : public A_ufo {

public:

	A_spacecraft( int const velocity, int const skin );
	A_spacecraft( A_spacecraft const & src );
	virtual ~A_spacecraft();

	A_spacecraft &	operator=( A_spacecraft const & rhs );

	virtual void	move() = 0;

	int				take_damage( int const );
	bool			check_collision( A_spacecraft *opposing_force, size_t size );

	int				hp;

};

#endif
