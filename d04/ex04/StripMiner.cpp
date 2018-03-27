/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:03:06 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:12:22 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner( void )
{ }

StripMiner::~StripMiner()
{ }

StripMiner &		StripMiner::operator=( StripMiner const & rhs )
{
	(void)rhs;
	return *this;
}

void				StripMiner::mine( IAsteroid * a )
{
	std::cout << "* strip mining ... got " << a->beMined(this) << \
		" ! *" << std::endl;
}
