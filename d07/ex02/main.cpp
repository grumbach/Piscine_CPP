/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:01:14 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/04 16:58:14 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int			main( void )
{
	Array<int> int_array(42);

	int_array[21] = 42;

	for (size_t i = 0; i < 42; i++)
		std::cout << i << ":\t" << int_array[i] << std::endl;
	try
	{
		int_array[42];
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
