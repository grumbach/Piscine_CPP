/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:53:48 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 21:00:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( void ) : A_spacecraft()
{ }

Player::Player( Player const & src ) : A_spacecraft(src)
{ }

Player::~Player()
{ }


Player &			Player::operator=( Player const & rhs )
{ }

void				Player::shoot_missile()
{ }
