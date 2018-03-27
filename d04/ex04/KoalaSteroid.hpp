/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:16:18 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:13:46 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOCALSTEROIDS_H
# define BOCALSTEROIDS_H

#include <iostream>
#include "IAsteroid.hpp"

class BocalSteroid : public IAsteroid {

public:

	BocalSteroid( void );
	BocalSteroid( BocalSteroid const & src );
	~BocalSteroid();

	BocalSteroid &			operator=( BocalSteroid const & rhs );

	std::string 			getName() const;

	virtual std::string		beMined(DeepCoreMiner *) const;
	virtual std::string		beMined(StripMiner *) const;

private:

	std::string			name;

};

#endif
