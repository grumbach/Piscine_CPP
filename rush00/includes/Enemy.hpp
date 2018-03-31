/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 19:50:06 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include "A_spacecraft.hpp"
#include "Enemy_missile.hpp"

class Enemy : public A_spacecraft {

public:

	Enemy( void );
	Enemy( Enemy const & src );
	~Enemy();

	Enemy &			operator=( Enemy const & rhs );

	virtual void	move();

	Enemy_missile	missiles[ENEMIES_MISSILES];

private:

	void			_shoot_missile();

	int				_spawn_delay;

};

#endif
