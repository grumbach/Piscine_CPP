/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:47:51 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:48:34 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine( void )
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine( TacticalMarine const & src )
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
	// this class has no property, so there's nothing to copy here.
	(void)src;
}

TacticalMarine::~TacticalMarine( void )
{
	std::cout << "Aaargh ..." << std::endl;
}

void	TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void	TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

ISpaceMarine* TacticalMarine::clone( void ) const
{
	return new TacticalMarine(*this);
}

TacticalMarine& TacticalMarine::operator=(TacticalMarine const & rhs)
{
	(void)rhs;
	return *this;
}

std::ostream & operator<<( std::ostream & o, TacticalMarine const & tm )
{
	(void)tm;
	o << "TacticalMarine: " << std::endl;

	return o;
}
