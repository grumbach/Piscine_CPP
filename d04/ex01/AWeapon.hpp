/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:46:52 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:47:04 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon {

private:

	std::string const name;
	int apcost;
	int damage;

public:

	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon( AWeapon const & src );
	~AWeapon();
	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

	AWeapon & operator=( AWeapon const & rhs );

};

#endif
