/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:54:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 15:48:11 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int				main()
{
	FragTrap	clap("CL4PTR4P");
	FragTrap	trap;

	clap.rangedAttack("Jack");
	clap.meleeAttack("door");
	clap.takeDamage(42);
	clap.beRepaired(101010);

	clap.vaulthunter_dot_exe("stairs");
	clap.vaulthunter_dot_exe("stairs");

	trap.vaulthunter_dot_exe("stairs");
	trap.vaulthunter_dot_exe("stairs");
	return (0);
}
