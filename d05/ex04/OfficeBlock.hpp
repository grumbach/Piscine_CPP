/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:08:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 11:38:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock {

public:

	class InvalidOfficeBlockException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Office block is not operational!"); }
	};

	class CrashOfficeBlockException : public std::exception {
	public:
		virtual const char *what() const throw()
			{ return ("Office block failed to deliver!"); }
	};

	OfficeBlock( void );
	OfficeBlock( Intern *intern, Bureaucrat *bureaucrat1, Bureaucrat *bureaucrat2 );
	OfficeBlock( OfficeBlock const & src );
	virtual ~OfficeBlock();
	OfficeBlock &operator=( OfficeBlock const & rhs );

	void					setIntern( Intern * a );
	void					setSigner( Bureaucrat * a );
	void					setExecutor( Bureaucrat * a );

	void					doBureaucracy( std::string const & form_type, \
								std::string const & target ) const;

private:

	Intern		*_intern;
	Bureaucrat	*_bureaucrat1;
	Bureaucrat	*_bureaucrat2;

};


std::ostream &		operator<<( std::ostream & o, OfficeBlock const & i );



#endif
