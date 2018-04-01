/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:50:37 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:09:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_H
# define STAR_H

#include "A_ufo.hpp"

class Star : public A_ufo {

public:

	Star( void );
	Star( Star const & src );
	~Star();

	Star &			operator=( Star const & rhs );

	virtual void	move();

};

#endif
