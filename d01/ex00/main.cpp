/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:24:03 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/20 19:28:44 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap()
{
	Pony	*pony = new Pony(2, 1);

	std::cout << "[ponyOnTheHeap]Living ponies: " << Pony::_ponies_alive() << std::endl;

	std::cout << "Heap Pony!" << std::endl << std::endl;
	pony->show();
	std::cout << std::endl;

	delete pony;
}

void	ponyOnTheStack()
{
	Pony	pony(3, 6);

	std::cout << "[ponyOnTheStack]Living ponies: " << Pony::_ponies_alive() << std::endl;

	std::cout << "Stack Pony!" << std::endl << std::endl;
	pony.show();
	std::cout << std::endl;
}

int			main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();

	std::cout << "[main]Living ponies: " << Pony::_ponies_alive() << std::endl;
	return (0);
}
