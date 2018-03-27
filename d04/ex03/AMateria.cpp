/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:03:22 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:22:26 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
	: type_("default")
	, xp_(10)
{ }

AMateria::AMateria( std::string const & type )
	: type_(type)
	, xp_(10)
{ }

AMateria::AMateria( AMateria const & src )
	: type_(src.getType())
	, xp_(10)
{ }

AMateria::~AMateria()
{ }

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	this->xp_ = rhs.getXP();

	return *this;
}

/*
** Features
*/

std::string const &		AMateria::getType() const
{
	return this->type_;
}

unsigned int			AMateria::getXP() const
{
	return this->xp_;
}

void					AMateria::use( ICharacter& target )
{
	//TODO
	(void ) target;
	// target.xp += this->xp_;
}
