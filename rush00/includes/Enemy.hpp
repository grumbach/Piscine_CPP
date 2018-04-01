/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include "A_spacecraft.hpp"
#include "Missile.hpp"

class Enemy : public A_spacecraft {

public:

	Enemy( void );
	Enemy( Enemy const & src );
	virtual ~Enemy();

	Enemy &			operator=( Enemy const & rhs );

	virtual void	move();

	Missile			missiles[ENEMIES_MISSILES];

private:

	void			_shoot_missile();
	int				_spawn_delay;

};

#endif
