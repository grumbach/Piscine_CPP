/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:45:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:46:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

private:

	std::string name;
	int AP;
	AWeapon *weapon;

public:

	Character(Character const & src);
	Character(std::string const & name);
	~Character(void);

	void					recoverAP();
	void					equip(AWeapon*);
	void					attack(Enemy*);
	std::string				getName() const;
	int						getAP() const;
	std::string				getWeapon() const;

	Character & operator=( Character const & rhs );

};

std::ostream &				operator<<( std::ostream & o, Character const & i );

#endif
