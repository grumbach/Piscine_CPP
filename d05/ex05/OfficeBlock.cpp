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


void					OfficeBlock::setIntern( Intern * a )
{
	this->_intern = a;
}

void					OfficeBlock::setSigner( Bureaucrat * a )
{
	this->_bureaucrat1 = a;
}

void					OfficeBlock::setExecutor( Bureaucrat * a )
{
	this->_bureaucrat2 = a;
}

bool					OfficeBlock::isComplete() const
{
	return (this->_intern && this->_bureaucrat1 && this->_bureaucrat2);
}

bool					OfficeBlock::hasSigner() const
{
	return (this->_bureaucrat1);
}

bool					OfficeBlock::hasExecutor() const
{
	return (this->_bureaucrat2);
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
