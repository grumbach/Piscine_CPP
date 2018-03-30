/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:39:37 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/29 16:14:00 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	class CannotOpenException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Failed opening file _shrubbery!"); }
	};

	ShrubberyCreationForm( std::string const & target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm &			operator=( ShrubberyCreationForm const & rhs );

	bool			execute( Bureaucrat const & executor ) const;

};

#endif
