/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:45:32 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:08:27 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMININGLASER_H
# define IMININGLASER_H

#include "IAsteroid.hpp"

class IMiningLaser {

public:

	virtual ~IMiningLaser() {}
	virtual void	mine( IAsteroid * ) = 0;

};

#endif
