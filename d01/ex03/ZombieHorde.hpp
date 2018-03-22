/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:32:31 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 03:06:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

class ZombieHorde {

private:
	unsigned int	horde_size;
	Zombie			*zombies;

public:
	ZombieHorde (unsigned int horde_size);
	~ZombieHorde ();

	void		announce();
};

#endif
