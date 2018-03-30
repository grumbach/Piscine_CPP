/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:45:20 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:45:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist :  public AWeapon {

public:

	PowerFist(PowerFist const & src);
	PowerFist(void);
	~PowerFist(void);
	virtual void attack(void) const;

	PowerFist & operator=( PowerFist const & rhs );

};

#endif
