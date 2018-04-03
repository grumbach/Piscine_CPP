/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:35:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 16:35:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.h"

int		main(void)
{
	try
	{
		Form		darwin("Darwin", 42, 21);
		Form		dar("Dar", 42, 23);
		std::cout << darwin;
		std::cout << dar;

		Bureaucrat	steve("steve", 45);
		Bureaucrat	woz("woz", 12);

		woz.signForm(darwin);
		steve.signForm(dar);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form		linux("Linux", 12, 0);
		std::cout << linux;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form		windows("Windows", 1, 2147483647);
		std::cout << windows;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
