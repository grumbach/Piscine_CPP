/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:32:29 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:28:40 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice( void );
	Ice( Ice const & src );
	~Ice();

	AMateria *				clone( void ) const;
	void					use( ICharacter & target );

};

#endif
