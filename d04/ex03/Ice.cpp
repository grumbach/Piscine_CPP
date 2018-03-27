/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:31:17 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:28:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{ }

Ice::Ice( Ice const & src ) : AMateria(src)
{ }

Ice::~Ice()
{ }

/*
** Features
*/

AMateria *		Ice::clone( void ) const
{
	AMateria	*clone = new Ice();

	return clone;
}

void			Ice::use( ICharacter & target )
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
