/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:51:48 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:51:49 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main( void )
{
	TacticalMarine* bob = new TacticalMarine;
	AssaultTerminator* jim = new AssaultTerminator;
	ISpaceMarine* bill = new AssaultTerminator(*jim);
	ISpaceMarine* kek = new TacticalMarine(*bob);
	Squad* vlc = new Squad();
	vlc->push(bob);
	vlc->push(jim);
	vlc->push(bill);
	vlc->push(kek);
	std::cout << "There is " << vlc->getCount() << " units in the squad." << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		if (ISpaceMarine* cur = vlc->getUnit(i))
		{
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
	}
	ISquad *test = vlc;
	delete test;
	return 0;
}
