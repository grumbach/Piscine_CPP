/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:06:58 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:13:21 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal( void )
	: name("AsteroBocal")
{ }

AsteroBocal::AsteroBocal( AsteroBocal const & src )
	: name(src.getName())
{ }

AsteroBocal::~AsteroBocal()
{ }


AsteroBocal &		AsteroBocal::operator=( AsteroBocal const & rhs )
{
	this->name = rhs.getName();
	return *this;
}


std::string 		AsteroBocal::getName() const
{
	return this->name;
}

std::string			AsteroBocal::beMined(DeepCoreMiner *) const
{
	return "Thorite";
}

std::string			AsteroBocal::beMined(StripMiner *) const
{
	return "Flavium";
}
