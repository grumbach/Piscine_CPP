/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:51:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:33:42 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile( void ) : A_spacecraft(MISSILES_VELOCITY, MISSILES_SKIN)
{
	return ;
}

Missile::Missile( Missile const & src ) : A_spacecraft(src)
{
	*this = src;
}

Missile::~Missile()
{
	return ;
}


Missile &			Missile::operator=( Missile const & rhs )
{
	return *this;
}
