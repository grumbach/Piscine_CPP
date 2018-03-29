/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:35:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/29 19:28:35 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int		main(void)
{
	try
	{
		Bureaucrat					worker("agrumbac", 1);
		ShrubberyCreationForm		work("house");
		ShrubberyCreationForm		work1("house_copy");
		work1 = work;
		worker.executeForm(work1);

		PresidentialPardonForm		work2("rbadia");
		worker.executeForm(work2);

		RobotomyRequestForm			work3("hmasson");
		worker.executeForm(work3);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat					worker("angavrel", 150);
		ShrubberyCreationForm		work("microsoft_vba");

		worker.executeForm(work);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat					worker("kneth", 150);
		PresidentialPardonForm		work2("htmlcss");
		worker.executeForm(work2);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
