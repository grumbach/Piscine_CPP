/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:46:12 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:46:13 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle :  public AWeapon {

public:

	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const & src);
	~PlasmaRifle(void);

	virtual void attack(void) const;
	PlasmaRifle & operator=( PlasmaRifle const & rhs );

};

#endif
