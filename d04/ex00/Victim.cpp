/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:30:31 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 15:51:23 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim( std::string name )
	: name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim( Victim const & src )
	:name(src.getName())
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim( void )
{ }

Victim::~Victim()
{
	std::cout << "Victim " << name << \
		" just died for no apparent reason !" << std::endl;
}

Victim &				Victim::operator=( Victim const & rhs )
{
	this->name = rhs.getName();

	return *this;
}

/*
** Features
*/

std::string const &		Victim::getName() const
{
		return this->name;
}

void					Victim::getPolymorphed() const
{
	std::cout << this->name << \
		" has been turned into a cute little sheep !" << std::endl;
}


std::ostream &		operator<<( std::ostream & o, Victim const & i )
{
	o << "I'm " << i.getName() << " and I like otters !" << std::endl;

	return o;
}
