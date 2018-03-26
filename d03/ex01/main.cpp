/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:54:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 17:03:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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



	ScavTrap	vclap("tutu");
	ScavTrap	vtrap;

	vclap.rangedAttack("Jack");
	vclap.meleeAttack("door");
	vclap.takeDamage(42);
	vclap.beRepaired(101010);

	vclap.challengeNewcomer("stairs");
	vclap.challengeNewcomer("stairs");
	vclap.challengeNewcomer("stairs");
	vclap.challengeNewcomer("stairs");

	vtrap.challengeNewcomer("stairs");
	vtrap.challengeNewcomer("stairs");
	return (0);
}
