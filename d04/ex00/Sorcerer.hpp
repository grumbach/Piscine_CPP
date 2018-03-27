/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:30:29 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 15:35:15 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include "Victim.hpp"

class Sorcerer {

public:

	Sorcerer( std::string name, std::string title );
	Sorcerer( Sorcerer const & src );
	~Sorcerer();

	Sorcerer &				operator=( Sorcerer const & rhs );

	std::string const &		getName( void ) const;
	std::string const &		getTitle( void ) const;
	void					polymorph( Victim const & victim ) const;

private:

	Sorcerer( void );

	std::string				name;
	std::string				title;

};


std::ostream &				operator<<( std::ostream & o, Sorcerer const & i );


#endif
