/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:51:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:11:57 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human ()
{ }
Human::~Human ()
{ }

std::string		Human::identify()
{
	return (this->brain.identify());
}

Brain			&Human::getBrain()
{
	return (this->brain);
}
