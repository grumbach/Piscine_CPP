/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:18:47 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/05 22:36:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int		main( void )
{
	{
		std::string				str("c++");
		std::string::iterator	i;
		try
		{
			easyfind<std::string> (str, 'C');
		}
		catch (std::exception & e)
		{
			std::cout << "---Didn't find 'C' in c++" << std::endl;
		}
		i = easyfind<std::string> (str, '+');
		if (*i)
			std::cout << "---Found '+' in c++" << std::endl;

	}
	{
		const int					arr[] = {42,28,-503,126};
		std::vector<int>			vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::vector<int>::iterator	i;
		try
		{
			easyfind< std::vector<int> > (vec, -42);
		}
		catch (std::exception & e)
		{
			std::cout << "---Didn't find -42 in {42,28,-503,126}" << std::endl;
		}
		i = easyfind< std::vector<int> > (vec, 28);
		if (*i)
			std::cout << "---Found 28 in {42,28,-503,126}" << std::endl;
	}

	return (0);
}
