/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:24:20 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 17:59:35 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock( void )
{ }

OfficeBlock( Intern *intern, Bureaucrat *bureaucrat1, Bureaucrat *bureaucrat2 )
	:_intern(intern);
	,_bureaucrat1(bureaucrat1);
	,_bureaucrat2(bureaucrat2);
{ }

~OfficeBlock()
	:_intern(NULL);
	,_bureaucrat1(NULL);
	,_bureaucrat2(NULL);
{ }


void					setIntern( Intern * a )
{
	this->_intern = a;
}

void					setSigner( Bureaucrat * a )
{
	this->_bureaucrat1 = a;
}

void					setExecutor( Bureaucrat * a )
{
	this->_bureaucrat2 = a;
}


void					doBureaucracy( std::string const & form_type, \
							std::string const & target ) const
{
	if (!this->_intern || !this->_bureaucrat1 || !this->_bureaucrat2)
		throw OfficeBlock::InvalidOfficeBlockException();
	else
	{
		try
		{
			this->_intern->makeForm(form_type, target);
		}
		catch (std::exception & e)
		{
			throw e;
		}
	}
}
