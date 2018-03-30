/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:40:34 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 17:05:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern( void )
{ }

Intern::Intern( Intern const & src )
{ (void)src; }

Intern::~Intern()
{ }


Intern &	Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}


Form		*Intern::makeForm( std::string const & form_type, \
						std::string const & target ) const
{
	Form	*form = NULL;

	if (form_type == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else if (form_type == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (form_type == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else
		std::cout << "ERROR: Intern can't create "<< form_type << std::endl;

	if (form)
		std::cout << "Intern creates " << form_type << std::endl;
	return form;
}
