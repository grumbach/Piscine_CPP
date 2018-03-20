/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:28:34 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/21 20:22:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include "Zombie.hpp"
#include <iostream>
#include <ctime>

class ZombieEvent {

private:
	std::string		ZombieType;

public:
	ZombieEvent (std::string default_type);
	~ZombieEvent ();

	void			setZombieType(std::string type);
	Zombie*			newZombie(std::string name);
};

#endif
