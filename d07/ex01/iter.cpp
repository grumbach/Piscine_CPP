/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:08:14 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/04 13:57:59 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
void	iter(T *array, size_t size, void (*function)(T))
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

template < typename T >
void	print(T a)
{
	std::cout << a << std::endl;
}

/*
** Test
*/

int		main()
{
	int				tutu[] = {1, 5, 42, 56};
	float			tata[] = {42.4f, 65.43f, 432.212f};
	std::string		toto[] = {"aaa", "bbb"};

	std::cout << "___________ints" << std::endl;
	iter(tutu, 4, print);
	std::cout << "___________floats" << std::endl;
	iter(tata, 3, print);
	std::cout << "___________strings" << std::endl;
	iter(toto, 2, print);

	return (0);
}
