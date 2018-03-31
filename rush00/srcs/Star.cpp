/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 19:40:46 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

Star::Star( void ) : A_ufo(STARS_DELAY, STARS_SKIN)
{ }

Star::Star( Star const & src ) : A_ufo(src)
{ }

Star::~Star()
{ }


Star &			Star::operator=( Star const & rhs )
{
	(void)rhs;
	return *this;
}

void			Star::move()
{
	if (this->out_of_bounds())
	{
		this->pos_y = 0;
		this->pos_x = RANDOM_X_SPAWN;
	}
	else if (this->can_move())
		this->pos_y++;
}
