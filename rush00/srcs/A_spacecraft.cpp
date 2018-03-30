/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_spacecraft.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:36 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 21:01:25 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_spacecraft.hpp"

A_spacecraft::A_spacecraft( void ) : A_ufo()
{ }

A_spacecraft::A_spacecraft( A_spacecraft const & src ) : A_ufo(src)
{ }

A_spacecraft::~A_spacecraft()
{ }


A_spacecraft &			A_spacecraft::operator=( A_spacecraft const & rhs )
{ }
