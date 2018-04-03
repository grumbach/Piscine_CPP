/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:24:20 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 17:10:28 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock( void )
	: _intern(NULL)
	, _bureaucrat1(NULL)
	, _bureaucrat2(NULL)
{ }

OfficeBlock::OfficeBlock( Intern *intern, Bureaucrat *bureaucrat1, Bureaucrat *bureaucrat2 )
	: _intern(intern)
	, _bureaucrat1(bureaucrat1)
	, _bureaucrat2(bureaucrat2)
{ }

OfficeBlock::~OfficeBlock()
{ }


void	OfficeBlock::setIntern( Intern * intern )
{
	this->_intern = intern;
}

Intern * OfficeBlock::getIntern( void )
{
	return this->_intern;
}

void	OfficeBlock::setSigner( Bureaucrat * bureaucrat )
{
	this->_bureaucrat1 = bureaucrat;
}

Bureaucrat * OfficeBlock::getSigner( void )
{
	return this->_bureaucrat1;
}

void	OfficeBlock::setExecutor( Bureaucrat * bureaucrat )
{
	this->_bureaucrat2 = bureaucrat;
}

Bureaucrat * OfficeBlock::getExecutor( void )
{
	return this->_bureaucrat2;
}

void	OfficeBlock::doBureaucracy( std::string const & form_type, std::string const & target ) const
{
	if (!this->_intern || !this->_bureaucrat1 || !this->_bureaucrat2)
		throw OfficeBlock::InvalidOfficeBlockException();
	else
	{
		try
		{
			Form *form = this->_intern->makeForm(form_type, target);
			if (form)
			{
				this->_bureaucrat1->signForm(*form);
				this->_bureaucrat2->executeForm(*form);
			}
			else
			{
				throw OfficeBlock::CrashOfficeBlockException();
			}
		}
		catch (std::exception & e)
		{
			throw e;
		}
	}
}
