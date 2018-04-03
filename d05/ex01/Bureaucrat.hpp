/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:59:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 15:15:53 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include "Form.hpp"

# define LOWEST_GRADE			150
# define HIGHEST_GRADE			1

class Form;

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Grade too high : cannot be God"); }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Grade too low : cannot be employed anymore"); }
	};

	Bureaucrat( std::string const & name, int const & grade );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat();

	Bureaucrat &		operator=( Bureaucrat const & rhs );

	std::string 		getName( void ) const;
	int 				getGrade( void ) const;
	void				UpGrade( void );
	void				DownGrade( void );
	void				signForm( Form & form ) const;

private:

	const std::string  	_name;
	int					_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif
