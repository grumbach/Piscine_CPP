/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:56:18 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
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
	virtual ~Player();

	Player &			operator=( Player const & rhs );

	void				shoot_missile();
	virtual void		move();
	void				apply_input( int const ch );
	void				set_bindings( int, int, int, int, int );

	Missile				missiles[MISSILES];

private:

	int					_binding_down;
	int					_binding_up;
	int					_binding_left;
	int					_binding_right;
	int					_binding_shoot;

};

#endif
