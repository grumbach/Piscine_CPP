/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:56:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:09:51 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEPCOREMINER_H
# define DEEPCOREMINER_H

#include <iostream>
#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {

public:

	DeepCoreMiner( void );
	~DeepCoreMiner();

	DeepCoreMiner &		operator=( DeepCoreMiner const & rhs );

	virtual void		mine( IAsteroid * a );

};

#endif
