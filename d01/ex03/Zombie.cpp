/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:28:21 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 01:42:02 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name)
	: type(type)
	, name(name)
{ }

Zombie::Zombie()
{ }

Zombie::~Zombie()
{ }

void		Zombie::announce()
{
	std::cout << "<" << this->name << " (";
	std::cout << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
}
