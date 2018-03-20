/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:28:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/21 20:17:58 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

private:
	std::string		type;
	std::string		name;

public:
	Zombie (std::string type, std::string name);
	~Zombie ();

	void			announce();
};

#endif
