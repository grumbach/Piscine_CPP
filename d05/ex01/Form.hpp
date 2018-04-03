/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:36:55 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 16:36:04 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Grade too high : nobody can sign this!"); }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Grade too low for form!"); }
	};

	Form( std::string const & name, int const required_grade_sign, int const required_grade_exec );
	Form( Form const & src );
	~Form();

	Form &			operator=( Form const & rhs );

	std::string 	getName( void ) const;
	int 			getRequiredGradeSign( void ) const;
	int 			getRequiredGradeExec( void ) const;
	bool 			getSignedStatus( void ) const;
	bool			beSigned( Bureaucrat const & signer );

private:

	std::string		_name;
	int				_required_grade_sign;
	int				_required_grade_exec;
	bool			_signed;

};


std::ostream &		operator<<( std::ostream & o, Form const & i );

/*
It has a name, a boolean indicating whether it is signed (at the beginning, it’s not), a grade required to sign it, and a grade required to execute it. The name and grades are constant, and all these attributes are private (not protected). The grades are subject to the same constraints as in the Bureaucrat, and exceptions will be thrown if any of them are out of bounds, Form::GradeTooHighException and Form::GradeTooLowException.
*/

#endif
