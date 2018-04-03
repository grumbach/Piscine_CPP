/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:39:44 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/29 16:47:14 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : Form("PresidentialPardonForm", target , 25, 5)
{ }

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form(src)
{ }

PresidentialPardonForm::~PresidentialPardonForm()
{ }


PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	((Form &)*this) = rhs;

	return *this;
}

/*
** Features
*/

bool			PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (!this->getSignedStatus())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getRequiredExecGrade())
	{
		throw Form::GradeTooLowException();
		return false;
	}

	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;

	return true;
}
