/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:54:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 10:25:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

int				main()
{
	SuperTrap	tramp("tutu");
	NinjaTrap	ninja;

	std::cout << "tramp Hit Points: " << tramp.hit_points << std::endl;
	std::cout << "tramp Melee attack damage: " << tramp.melee_attack_damage << std::endl;
	std::cout << "tramp name: " << tramp.name << std::endl;

	tramp.meleeAttack("melee target");
	tramp.rangedAttack("ranged target");

	tramp.vaulthunter_dot_exe("Vault");
	tramp.ninjaShoebox(ninja);

	return (0);
}
