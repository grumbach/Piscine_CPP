/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:52:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 11:33:50 by agrumbac         ###   ########.fr       */
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

/*
	m 109   0        0
	r 114   5        1
	s 115   6        2
*/

void	Human::action(std::string const & action_name, std::string const & target) const
{
	typedef void	(Human::*actions)(std::string const &) const;
	actions			all[3] =
	{
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	char			index = action_name[0];
	index -= 109;
	index /= 3;

	actions chosen = all[index % 3];
	(this->*chosen)(target);
}


Human::Human ()
{ }

Human::~Human ()
{ }
