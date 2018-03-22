/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:38:34 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:50:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {

private:
	std::string		name;
	Weapon			&weapon;

public:
	HumanA (std::string name, Weapon &weapon);
	~HumanA ();

	void			attack() const;
};
