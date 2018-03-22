/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:52:09 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 16:35:12 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int			main(void)
{
	Human	attacker;

	attacker.action("melee", "Bitcoin");
	attacker.action("ranged", "npm install");
	attacker.action("shout", "Windows");

	return (0);
}
