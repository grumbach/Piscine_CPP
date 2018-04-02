/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:43:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 11:45:31 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string const & name, std::string const & target, \
	int const required_sign_grade, int const required_exec_grade )
	: _name(name)
	, _target(target)
	, _required_sign_grade(required_sign_grade)
	, _required_exec_grade(required_exec_grade)
	, _signed(false)
{
	if (this->_required_sign_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_sign_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (this->_required_exec_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_exec_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::Form( Form const & src )
	: _name(src.getName())
	, _target(src.getTarget())
	, _required_sign_grade(src.getRequiredSignGrade())
	, _required_exec_grade(src.getRequiredExecGrade())
	, _signed(src.getSignedStatus())
{
	if (this->_required_sign_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_sign_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (this->_required_exec_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_exec_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::~Form()
{ }

Form &			Form::operator=( Form const & rhs )
{
	this->_name = rhs.getName();
	this->_target = rhs.getTarget();
	this->_required_sign_grade = rhs.getRequiredSignGrade();
	this->_required_exec_grade = rhs.getRequiredExecGrade();
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

std::string 	Form::getTarget( void ) const
{
	return (this->_target);
}

int				Form::getRequiredSignGrade( void ) const
{
	return (this->_required_sign_grade);
}

int				Form::getRequiredExecGrade( void ) const
{
	return (this->_required_exec_grade);
}

bool 			Form::getSignedStatus( void ) const
{
	return (this->_signed);
}

bool			Form::beSigned( Bureaucrat const & signer )
{
	if (signer.getGrade() > this->_required_sign_grade)
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
	o << i.getName() << ", form requiring grade " << i.getRequiredExecGrade() << \
		"for exec and grade " << i.getRequiredSignGrade() << "for signing" <<
		(i.getSignedStatus() ? ", signed." : ", not signed yet.") << std::endl;

	return o;
}
