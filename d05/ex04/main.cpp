/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:35:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 13:33:14 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

int	main( void )
{
	{
		Intern      trponess;
		Bureaucrat  angavrel = Bureaucrat("dot NET core expert", 37);
		Bureaucrat  kneth = Bureaucrat("html css master", 12);
		OfficeBlock ob;
		ob.setIntern(&trponess);
		ob.setSigner(&kneth);
		ob.setExecutor(&angavrel);
		try
		{
			ob.doBureaucracy("robotomy request", "adjivas");
		}
		catch (OfficeBlock::InvalidOfficeBlockException & e)
		{
			std::cerr << "OFFICE ERROR: " << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Intern      trponess;
		Bureaucrat  angavrel = Bureaucrat("dot NET core expert", 37);
		OfficeBlock ob;
		ob.setIntern(&trponess);
		ob.setExecutor(&angavrel);
		try
		{
			ob.doBureaucracy("robotomy request", "adjivas");
		}
		catch (OfficeBlock::InvalidOfficeBlockException & e)
		{
			std::cerr << "OFFICE ERROR: " << e.what() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
