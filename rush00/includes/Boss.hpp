/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <stmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 00:35:45 by stmartin          #+#    #+#             */
/*   Updated: 2018/04/01 14:22:21 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_H
# define BOSS_H

#include "A_spacecraft.hpp"
#include "Missile.hpp"

class Boss : public A_spacecraft {

public:

	Boss( void );
	Boss( std::string const & name );
	Boss( Boss const & src );
	~Boss();

	Boss &			operator=( Boss const & rhs );
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
