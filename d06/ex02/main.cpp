/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:48:10 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/03 18:28:31 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base		*generate( void )
{
	int		type = std::rand() % 3;

	if (type == 0)
	{
		std::cout << "created A" << std::endl;
		return new A;
	}
	else if (type == 1)
	{
		std::cout << "created B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "created C" << std::endl;
		return new C;
	}
}

void		identify_from_pointer( Base * p )
{
	A		*tota;
	B		*totb;
	C		*totc;

	if ((tota = dynamic_cast<A *>(p)))
		std::cout << "identified * A" << std::endl;
	if ((totb = dynamic_cast<B *>(p)))
		std::cout << "identified * B" << std::endl;
	if ((totc = dynamic_cast<C *>(p)))
		std::cout << "identified * C" << std::endl;
}

void		identify_from_reference( Base & r )
{
	Base	*p = &r;
	A		*tota;
	B		*totb;
	C		*totc;

	if ((tota = dynamic_cast<A *>(p)))
		std::cout << "identified & A" << std::endl;
	if ((totb = dynamic_cast<B *>(p)))
		std::cout << "identified & B" << std::endl;
	if ((totc = dynamic_cast<C *>(p)))
		std::cout << "identified & C" << std::endl;
}

int			main( void )
{
	std::srand(std::time(nullptr));

	Base	*tutu = generate();

	identify_from_pointer(tutu);
	identify_from_reference(*tutu);

	return (0);
}

/*
Write a function "Base * generate(void);" that randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free to use anything you like for the randomness.
Write a function "void identify_from_pointer( Base * p );" that displays "A", "B" or "C" according to the real type of p.
Write a function "void identify_from_reference( Base & p );" that displays "A", "B" or "C" according to the real type of p.
Wrap these three functions in a program that prooves that everything works as in- tended. Including <typeinfo> is forbidden.
*/
