/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:30:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 15:50:06 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer( std::string name, std::string title )
	: name(name)
	, title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const & src )
	: name(src.getName())
	, title(src.getTitle())
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( void )
{ }

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << \
		", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &				Sorcerer::operator=( Sorcerer const & rhs )
{
	this->name = rhs.getName();
	this->title = rhs.getTitle();

	return *this;
}

/*
** Features
*/

std::string const &		Sorcerer::getName() const
{
	return this->name;
}

std::string const &		Sorcerer::getTitle() const
{
	return this->title;
}

void					Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}

std::ostream &			operator<<( std::ostream & o, Sorcerer const & i )
{
	o << "I am " << i.getName() << ", " << i.getTitle() << \
		", and I like ponies !" << std::endl;

	return o;
}
