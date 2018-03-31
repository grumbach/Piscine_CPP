/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_spacecraft.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:12:47 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_spacecraft.hpp"

A_spacecraft::A_spacecraft( int const velocity ) : A_ufo(velocity)
{
	return ;
}

A_spacecraft::A_spacecraft( A_spacecraft const & src ) : A_ufo(src)
{ }

A_spacecraft::~A_spacecraft()
{
	return ;
}


A_spacecraft &			A_spacecraft::operator=( A_spacecraft const & rhs )
{
	return *this;
}
