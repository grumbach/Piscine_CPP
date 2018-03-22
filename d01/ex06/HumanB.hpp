/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:00:59 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 10:13:37 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {

private:
	std::string		name;
	Weapon			*weapon;

public:
	HumanB (std::string name);
	~HumanB ();

	void			attack() const;
	void			setWeapon(Weapon *weapon);
};
