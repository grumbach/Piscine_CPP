/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:50:37 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_H
# define STAR_H

#include "A_ufo.hpp"

class Star : public A_ufo {

public:

	Star( void );
	Star( Star const & src );
	virtual ~Star();

	Star &			operator=( Star const & rhs );

	virtual void	move();

};

#endif
