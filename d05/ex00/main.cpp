/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:35:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 15:31:11 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	try
	{
		Bureaucrat		darwin("Darwin", 42);
		std::cout << darwin;

		std::cout << "# MacOS SnowLeopard, Darwin upgrade 28.. " << std::endl;
		darwin.UpGrade(28);
		std::cout << "# Darwin grade: " << darwin.getGrade() << std::endl;

		std::cout << "# Steve Jobs dies, Darwin downgrade.. " << std::endl;
		darwin.DownGrade(4000);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat		linux("Linux", 0);
		std::cout << linux;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat		windows("Windows", 2147483647);
		std::cout << windows;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
