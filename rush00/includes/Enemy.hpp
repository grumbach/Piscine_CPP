/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 19:54:26 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include "A_spacecraft.hpp"

class Enemy : public A_spacecraft {

public:

	Enemy( void );
	Enemy( Enemy const & src );
	~Enemy();

	Enemy &			operator=( Enemy const & rhs );

};

#endif
