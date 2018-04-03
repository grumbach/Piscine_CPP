/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:24:20 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 11:40:10 by agrumbac         ###   ########.fr       */
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

OfficeBlock::OfficeBlock( OfficeBlock const & src )
{ (void)src; }

OfficeBlock::~OfficeBlock()
{ }


void					OfficeBlock::setIntern( Intern * i )
{
	this->_intern = i;
}

void					OfficeBlock::setSigner( Bureaucrat * b )
{
	this->_bureaucrat1 = b;
}

void					OfficeBlock::setExecutor( Bureaucrat * b )
{
	this->_bureaucrat2 = b;
}


void					OfficeBlock::doBureaucracy( std::string const & form_type, \
							std::string const & target ) const
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

OfficeBlock &	OfficeBlock::operator=( OfficeBlock const & rhs )
{
	(void)rhs;
	return *this;
}