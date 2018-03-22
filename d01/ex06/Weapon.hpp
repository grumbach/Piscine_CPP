/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:16:14 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:36:06 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon {

private:
	std::string		type;

public:
	Weapon (std::string init_type);
	~Weapon ();

	const std::string		&getType(void) const;
	void					setType(std::string new_type);
};

#endif
