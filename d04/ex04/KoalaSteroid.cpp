/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:18:12 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:14:03 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid( void )
	: name("BocalSteroid")
{ }

BocalSteroid::BocalSteroid( BocalSteroid const & src )
	: name(src.getName())
{ }

BocalSteroid::~BocalSteroid()
{ }


BocalSteroid &		BocalSteroid::operator=( BocalSteroid const & rhs )
{
	this->name = rhs.getName();
	return *this;
}


std::string 		BocalSteroid::getName() const
{
	return this->name;
}

std::string			BocalSteroid::beMined(DeepCoreMiner *) const
{
	return "Zazium";
}

std::string			BocalSteroid::beMined(StripMiner *) const
{
	return "Krpite";
}
