/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_ufo.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:41:06 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_UFO_H
# define A_UFO_H

#include "settings.hpp"

class Game;

class A_ufo {

public:

	A_ufo( int const velocity, int const skin );
	A_ufo( A_ufo const & src );
	virtual ~A_ufo();

	A_ufo &			operator=( A_ufo const & rhs );

	bool			can_move();
	bool			out_of_bounds();
	virtual void	move() = 0;

	int				pos_x;
	int				pos_y;
	int				skin;
	int				velocity;

private:

	clock_t			_last_move;

};

#endif
