/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:35:06 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:29:28 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

#include <iostream>

class AMateria;

class ICharacter {

public:

	virtual ~ICharacter() {};

	virtual std::string const &		getName( void ) const = 0;
	virtual void 					equip( AMateria* m ) = 0;
	virtual void 					unequip( int idx ) = 0;
	virtual void 					use( int idx, ICharacter & target ) = 0;

};

#endif
