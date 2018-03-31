/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_spacecraft.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:55:41 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:06:33 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_SPACECRAFT_H
# define A_SPACECRAFT_H

#include "A_ufo.hpp"

class A_spacecraft : public A_ufo {

public:

	A_spacecraft( int const velocity, int const skin );
	A_spacecraft( A_spacecraft const & src );
	~A_spacecraft();

	A_spacecraft &	operator=( A_spacecraft const & rhs );

	virtual void	move() = 0;

	int				hp;

};

#endif
