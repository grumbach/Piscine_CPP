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

Form::Form( std::string const & name, int const required_grade_sign, int const required_grade_exec )
	: _name(name)
	, _required_grade_sign(required_grade_sign)
	, _required_grade_exec(required_grade_exec)
	, _signed(false)
{
	if (this->_required_grade_sign > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_grade_sign < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (this->_required_grade_exec > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_grade_exec < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::Form( Form const & src )
	: _name(src.getName())
	, _required_grade_sign(src.getRequiredGradeSign())
	, _required_grade_exec(src.getRequiredGradeExec())
	, _signed(src.getSignedStatus())
{
	if (this->_required_grade_sign > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_grade_sign < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (this->_required_grade_exec > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (this->_required_grade_exec < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

Form::~Form()
{ }

Form &			Form::operator=( Form const & rhs )
{
	this->_name = rhs.getName();
	this->_required_grade_sign = rhs.getRequiredGradeSign();
	this->_required_grade_exec = rhs.getRequiredGradeExec();
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

int 			Form::getRequiredGradeSign( void ) const
{
	return (this->_required_grade_sign);
}

int 			Form::getRequiredGradeExec( void ) const
{
	return (this->_required_grade_exec);
}

bool 			Form::getSignedStatus( void ) const
{
	return (this->_signed);
}

bool			Form::beSigned( Bureaucrat const & signer )
{
	if (signer.getGrade() > this->_required_grade_sign)
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
	o << "<" << i.getName() << ">, form signature requiring grade <" << i.getRequiredGradeSign() << ">";
	o << ", form execution requiring grade <" << i.getRequiredGradeExec() << ">";
	o << (i.getSignedStatus() ? " is signed." : " is not signed.") << std::endl;

	return o;
}
