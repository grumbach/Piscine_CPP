/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:59:59 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 11:41:09 by agrumbac         ###   ########.fr       */
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

void				Bureaucrat::signForm( Form & form ) const
{
	if (form.beSigned(*this))
		std::cout << this->_name << " signs form " << form.getName() << std::endl;
	else
	{
		std::cout << this->_name << " cannot sign form " << form.getName();
		std::cout << " because ";
		if (form.getSignedStatus())
			std::cout << "it's already signed!";
		else
			std::cout << "bureaucrat grade isn't high enough!";
		std::cout << std::endl;
	}
}

void				Bureaucrat::executeForm( Form const & form ) const
{
	if (form.execute(*this))
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	else
	{
		std::cout << this->_name << " cannot execute " << form.getName();
		std::cout << " because bureaucrat grade isn't high enough!" << std::endl;
	}
}

/*
** Grades from 1 (HIGHEST_GRADE) to 150 (LOWEST_GRADE)
** yeah.. it's reversed... but a bureaucrat does what he's asked to do.
*/

void				Bureaucrat::UpGrade( int const & levels )
{
	if (this->_grade - levels < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= levels;
}

void				Bureaucrat::DownGrade( int const & levels )
{
	if (this->_grade + levels > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += levels;
}


/*
** Stream Feeding
*/

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;

	return o;
}
