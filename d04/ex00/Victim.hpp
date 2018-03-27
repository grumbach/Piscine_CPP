/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:30:34 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 15:52:22 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
# define VICTIM_H

#include <iostream>

class Victim {

public:

	Victim( std::string name );
	Victim( Victim const & src );
	~Victim();

	Victim &				operator=( Victim const & rhs );

	std::string const &		getName( void ) const;
	virtual void			getPolymorphed( void ) const;

protected:

	Victim( void );

	std::string				name;

};


std::ostream &				operator<<( std::ostream & o, Victim const & i );


#endif
