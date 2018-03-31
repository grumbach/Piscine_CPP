/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy_boss.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:48:49 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 22:52:13 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_BOSS_H
# define ENEMY_BOSS_H

#include "Enemy.h"

class Enemy_boss : public Enemy {

public:

	Enemy_boss( void );
	Enemy_boss( std::string const & name );
	Enemy_boss( Enemy_boss const & src );
	~Enemy_boss();

	Enemy_boss &			operator=( Enemy_boss const & rhs );



};

#endif
