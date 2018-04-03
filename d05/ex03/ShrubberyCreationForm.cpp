/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:39:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/29 16:16:02 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : Form("ShrubberyCreationForm", target , 145, 137)
{ }

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form(src)
{ }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }


ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	((Form &)*this) = rhs;

	return *this;
}

/*
** Features
*/

bool			ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (!this->getSignedStatus())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getRequiredExecGrade())
		throw Form::GradeTooLowException();

	std::ofstream			fileout(this->getTarget() + "_shrubbery");

	if (!fileout.is_open())
		throw ShrubberyCreationForm::CannotOpenException();

	fileout << "               ,@@@@@@@," << std::endl;
	fileout << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	fileout << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	fileout << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	fileout << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	fileout << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	fileout << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	fileout << "       |o|        | |         | |" << std::endl;
	fileout << "       |.|        | |         | |" << std::endl;
	fileout << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	fileout.close();
	return true;
}
