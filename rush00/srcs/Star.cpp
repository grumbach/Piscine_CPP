/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:18:27 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

Star::Star( void ) : A_ufo(STARS_VELOCITY, STARS_SKIN)
{
	return ;
}

Star::Star( Star const & src ) : A_ufo(src)
{
	*this = src;
}

Star::~Star()
{
	return ;
}


Star &			Star::operator=( Star const & rhs )
{
	return *this;
}

void			Star::move()
{
	if (this->out_of_bounds())
	{
		this->pos_y = 0;
		this->pos_x = RANDOM_SPAWN;
	}
	else
		this->pos_y++;
}