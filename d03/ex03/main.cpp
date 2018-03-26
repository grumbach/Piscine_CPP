/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:54:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 18:56:46 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

int				main()
{
	ClapTrap	a("a");
	ScavTrap	b("b");
	FragTrap	c("c");
	NinjaTrap	d("d");

	d.ninjaShoebox(a);
	d.ninjaShoebox(b);
	d.ninjaShoebox(c);
	d.ninjaShoebox(d);

	return (0);
}
