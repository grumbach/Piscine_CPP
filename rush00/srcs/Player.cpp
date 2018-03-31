/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:53:48 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:20:32 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( void ) : A_spacecraft(0)
{
	return ;
}

Player::Player( Player const & src ) : A_spacecraft(src)
{
	*this = src;
}

Player::~Player()
{
	return ;
}


Player &			Player::operator=( Player const & rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < MISSILES; i++)
			this->missiles[i] = rhs.missiles[i];
	}
	return (*this);
}

void				Player::shoot_missile()
{
	std::cout << "piou piou" << std::endl;
}
