/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:40:14 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/04 11:50:38 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
void		swap(T & a, T & b)
{
	T		c = a;

	a = b;
	b = c;
}

template < typename T >
T const &	min(T const & a, T const & b)
{
	if (a < b)
		return a;
	else
		return b;
}

template < typename T >
T const &	max(T const & a, T const & b)
{
	if (a > b)
		return a;
	else
		return b;
}

/*
• swap : Swaps the values of two arguments. Does not return anything.
• min : Compares the two arguments and returns the smallest one.
	If the two arguments are equal, then it returns the second one.
• max : Compares the two arguments and returns the biggest one.
	If the two arguments are equal, then it returns the second one.
*/

int			main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return (0);
}

/* OUT
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/
