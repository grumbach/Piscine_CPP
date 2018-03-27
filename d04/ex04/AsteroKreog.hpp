/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:05:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:13:24 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROBOCAL_H
# define ASTEROBOCAL_H

#include <iostream>
#include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid {

public:

	AsteroBocal( void );
	AsteroBocal( AsteroBocal const & src );
	~AsteroBocal();

	AsteroBocal &			operator=( AsteroBocal const & rhs );

	std::string 			getName() const;

	virtual std::string		beMined(DeepCoreMiner *) const;
	virtual std::string		beMined(StripMiner *) const;

private:

	std::string			name;

};

#endif
