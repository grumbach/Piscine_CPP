/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:30:21 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 15:57:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon( std::string name ): Victim(name)
{
	this->name = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( Peon const & src ): Victim(src)
{
	this->name = src.getName();
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( void )
{ }

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

/*
** Features
*/

void					Peon::getPolymorphed() const
{
	std::cout << this->name << \
		" has been turned into a pink pony !" << std::endl;
}
