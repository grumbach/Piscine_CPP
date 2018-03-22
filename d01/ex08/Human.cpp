/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:52:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 16:32:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target) const
{
	std::cout << "Human used 51% attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) const
{
	std::cout << "Human used DDOS attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) const
{
	std::cout << "Human used ping on " << target << std::endl;
}


void	Human::action(std::string const & action_name, std::string const & target) const
{
	typedef void	(Human::*actions)(std::string const &) const;
	std::map <std::string, actions> mapping;
	mapping.insert(std::make_pair("melee" , &Human::meleeAttack));
	mapping.insert(std::make_pair("ranged" , &Human::rangedAttack));
	mapping.insert(std::make_pair("shout" , &Human::intimidatingShout));

	actions chosen = mapping[action_name];
	(this->*chosen)(target);
}


Human::Human ()
{ }

Human::~Human ()
{ }
