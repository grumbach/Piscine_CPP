/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:51:57 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 17:11:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy( void )
{
	for (size_t i = 0; i < OFFICES; i++)
		_offices[i].setIntern(&_interns[i]);
}

CentralBureaucracy::CentralBureaucracy( CentralBureaucracy const & src )
{ (void)src; }

CentralBureaucracy::~CentralBureaucracy()
{ }


CentralBureaucracy &	CentralBureaucracy::operator=( CentralBureaucracy const & rhs )
{
	(void)rhs;
	return *this;
}


bool					CentralBureaucracy::feed_company( Bureaucrat * livestock)
{
	for (size_t i = 0; i < OFFICES; i++)
	{
		if (!_offices[i].isComplete())
		{
			if (!_offices[i].hasSigner())
				_offices[i].setSigner(livestock);
			else if (!_offices[i].hasExecutor())
				_offices[i].setExecutor(livestock);
			return true;
		}
	}
	return false;
}
