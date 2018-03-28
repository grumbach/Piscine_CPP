/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:43:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 16:30:55 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string const & name, int const required_grade )
	: _name(name)
	, _required_grade(required_grade)
	, _signed(false)
{
	if (this->_required_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::Form( Form const & src )
	: _name(src.getName())
	, _required_grade(src.getRequiredGrade())
	, _signed(src.getSignedStatus())
{
	if (this->_required_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::~Form()
{ }

Form &			Form::operator=( Form const & rhs )
{
	this->_name = rhs.getName();
	this->_required_grade = rhs.getRequiredGrade();
	this->_signed = rhs.getSignedStatus();

	return *this;
}

/*
** Features
*/

std::string 	Form::getName( void ) const
{
	return (this->_name);
}

int 			Form::getRequiredGrade( void ) const
{
	return (this->_required_grade);
}

bool 			Form::getSignedStatus( void ) const
{
	return (this->_signed);
}

bool			Form::beSigned( Bureaucrat const & signer )
{
	if (signer.getGrade() > this->_required_grade)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		return false;
	else
		return (this->_signed = true);
}

/*
** Stream Feeding
*/


std::ostream &		operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", form requiring grade " << i.getRequiredGrade() << \
		(i.getSignedStatus() ? ", signed." : ", not signed yet.") << std::endl;

	return o;
}
