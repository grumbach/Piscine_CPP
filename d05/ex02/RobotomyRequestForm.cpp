/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:39:41 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/29 16:44:09 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form("RobotomyRequestForm", target , 72, 45)
{
	std::srand(std::time(nullptr));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form(src)
{
	std::srand(std::time(nullptr));
}

RobotomyRequestForm::~RobotomyRequestForm()
{ }


RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	((Form &)*this) = rhs;

	return *this;
}

/*
** Features
*/

bool			RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (executor.getGrade() > this->getRequiredExecGrade())
		throw Form::GradeTooLowException();

	system("afplay drill.mp3");

	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->getTarget() << "'s robotomy was a failure..." << std::endl;
	return true;
}
//that <target> has been robotomized successfully 50% of the time. the rest of times, tells us it’s a failure.
