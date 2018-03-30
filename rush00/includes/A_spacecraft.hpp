/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_spacecraft.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:55:41 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 19:22:00 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_SPACECRAFT_H
# define A_SPACECRAFT_H

#include "A_ufo.hpp"

class A_spacecraft : public A_ufo {

public:

	A_spacecraft( void );
	A_spacecraft( A_spacecraft const & src );
	~A_spacecraft();

	A_spacecraft &	operator=( A_spacecraft const & rhs );

	int			hp;

};

#endif
