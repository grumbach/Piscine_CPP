/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:59:59 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 15:24:21 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const & name, int const & grade )
	: _name(name)
	, _grade(grade)
{
	if (this->_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
	: _name(src.getName())
	, _grade(src.getGrade())
{
	if (this->_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{ }

Bureaucrat &		Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs.getGrade();

	return *this;
}

/*
** Features
*/

std::string 		Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int 				Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

/*
** Grades from 1 (HIGHEST_GRADE) to 150 (LOWEST_GRADE)
** yeah.. it's reversed... but a bureaucrat does what he's asked to do.
*/

void				Bureaucrat::UpGrade( void )
{
	if (this->_grade - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void				Bureaucrat::DownGrade( void )
{
	if (this->_grade + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}


/*
** Stream Feeding
*/

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;

	return o;
}
