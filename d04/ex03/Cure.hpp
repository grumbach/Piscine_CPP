/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:16:55 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:29:46 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure( void );
	Cure( Cure const & src );
	~Cure();

	AMateria *				clone( void ) const;
	void					use( ICharacter & target );

};

#endif
