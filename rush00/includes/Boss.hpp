/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <stmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 00:35:45 by stmartin          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_H
# define BOSS_H

#include "A_spacecraft.hpp"
#include "Missile.hpp"
#include "Player.hpp"

class Boss : public A_spacecraft {

public:

	Boss( void );
	Boss( std::string const & name );
	Boss( Boss const & src );
	virtual ~Boss();

	Boss &			operator=( Boss const & rhs );

	void			awaken( int const score );
	void			check_collision( Player & player );
	void			move();
	void			draw_missiles();
	void			draw();

	Missile			missiles[BOSS_MISSILES];

private:

	void			_shoot_missile();

	int				_side_move;
	int				_change_side;
};

#endif
