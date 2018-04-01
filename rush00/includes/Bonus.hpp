/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <stmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:20:22 by stmartin          #+#    #+#             */
/*   Updated: 2018/04/01 21:39:52 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
#define BONUS_H

#include "A_spacecraft.hpp"
#include "Player.hpp"

class Bonus : public A_spacecraft {

public:

	Bonus( void );
	Bonus( Bonus const & src );
	virtual ~Bonus();

	void			check_collision( Player & player );

	Bonus &			operator=( Bonus const & rhs );

	virtual void	move();

private:

	int				_spawn_delay;

};



#endif
