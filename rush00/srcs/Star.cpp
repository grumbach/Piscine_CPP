/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:20:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

Star::Star( void ) : A_ufo(STARS_VELOCITY)
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
