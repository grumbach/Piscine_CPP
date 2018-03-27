/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:59:11 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:10:58 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner( void )
{ }

DeepCoreMiner::~DeepCoreMiner()
{ }

DeepCoreMiner &		DeepCoreMiner::operator=( DeepCoreMiner const & rhs )
{
	(void)rhs;
	return *this;
}

void				DeepCoreMiner::mine( IAsteroid * a )
{
	std::cout << "* mining deep ... got " << a->beMined(this) << \
		" ! *" << std::endl;
}
