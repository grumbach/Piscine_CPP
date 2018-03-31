/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy_missile.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:06:27 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 19:09:34 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_MISSILE_H
# define ENEMY_MISSILE_H

#include "Missile.hpp"

class Enemy_missile : public Missile {

public:

	Enemy_missile( void );
	Enemy_missile( Enemy_missile const & src );
	~Enemy_missile();

	Enemy_missile &			operator=( Enemy_missile const & rhs );

	virtual void			move();

};

#endif
