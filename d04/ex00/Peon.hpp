/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:30:24 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 15:49:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon : public Victim {

public:

	Peon( std::string name );
	Peon( Peon const & src );
	~Peon();

	void		getPolymorphed() const;

private:

	Peon( void );

};

#endif
