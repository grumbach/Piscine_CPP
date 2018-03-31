/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:56:18 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:10:27 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "A_spacecraft.hpp"
#include "Missile.hpp"

class Player : public A_spacecraft {

public:

	Player( void );
	Player( Player const & src );
	~Player();

	Player &			operator=( Player const & rhs );

	void				shoot_missile();
	virtual void		move();

	Missile				missiles[MISSILES];

};

#endif
