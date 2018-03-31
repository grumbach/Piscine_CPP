/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_ufo.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:14:41 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_ufo.hpp"

A_ufo::A_ufo( int const velocity )
	: pos_x(std::rand() % 42)//%TODO replace 42!  Game::_window_width)
	, pos_y(1)
	, velocity(velocity)
{
	return ;
}

A_ufo::A_ufo( A_ufo const & src )
{
	*this = src;
	return ;
}

A_ufo::~A_ufo()
{
	return ;
}


A_ufo &			A_ufo::operator=( A_ufo const & rhs )
{
	if (this != &rhs)
	{
		this->pos_x = rhs.pos_x;
		this->pos_y = rhs.pos_y;
		this->velocity = rhs.velocity;
	}
	return (*this);
}

void			A_ufo::move()
{ }
