/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 23:12:25 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/06 17:33:04 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int			main( void )
{
	std::srand(std::time(nullptr));
	{
		std::cout << "__________example number" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	try
	{
		std::cout << "__________error number" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch ( std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	{
		std::cout << "__________example array" << std::endl;
		Span sp = Span(10001);
		int *a = new int[10001];
		for (size_t i = 0; i < 10001; i++) {
			a[i] = std::rand();
		}
		sp.addArray(a, 10001);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	try
	{
		std::cout << "__________error array" << std::endl;
		Span sp = Span(12);
		int *a = new int[15];
		sp.addArray(a, 100);
	}
	catch ( std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "__________error span" << std::endl;
		Span sp = Span(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
