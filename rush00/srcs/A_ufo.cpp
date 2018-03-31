/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_ufo.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 20:59:38 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_ufo.hpp"

A_ufo::A_ufo( void )
{ 
    return ;
}

A_ufo::A_ufo( A_ufo const & src )
{ 
    *this = src;
    return ;
}

A_ufo::~A_ufo()
{ 
    return ;
}


A_ufo &			A_ufo::operator=( A_ufo const & rhs )
{ 
    if (this != &rhs)
    {
        this->pos_x = rhs.pos_x;
        this->pos_y = rhs.pos_y;
        this->direction = rhs.direction;
        this->velocity = rhs.velocity;
    }
    return (*this);
}

void			A_ufo::move()
{ }
