/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:16:57 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:30:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{ }

Cure::Cure( Cure const & src ) : AMateria(src)
{ }

Cure::~Cure()
{ }

/*
** Features
*/

AMateria *		Cure::clone( void ) const
{
	AMateria	*clone = new Cure();

	return clone;
}

void			Cure::use( ICharacter & target )
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
