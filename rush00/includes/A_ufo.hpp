/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_ufo.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:41:06 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:22:05 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_UFO_H
# define A_UFO_H

#include <iostream>
#include "settings.hpp"

class Game;

class A_ufo {

public:

	A_ufo( int const velocity );
	A_ufo( A_ufo const & src );
	~A_ufo();

	A_ufo &			operator=( A_ufo const & rhs );

	void			move();

	int				pos_x;
	int				pos_y;
	int				velocity;

};

#endif
