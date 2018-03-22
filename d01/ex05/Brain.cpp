/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:51:19 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:12:21 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{ }

Brain::~Brain()
{ }

std::string				Brain::identify()
{
	std::stringstream	ss;
	ss << (void *)this;
	std::string str = ss.str();
	return (str);
}

unsigned int			Brain::get_neurons()
{
	return (this->neurons);
}

void					Brain::set_neurons(unsigned int neurons)
{
	this->neurons = neurons;
}
