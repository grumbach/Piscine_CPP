/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:34:49 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 18:54:31 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:

	NinjaTrap( void );
	NinjaTrap( std::string const & name );
	NinjaTrap( NinjaTrap const & src );
	~NinjaTrap();

	NinjaTrap &		operator=( NinjaTrap const & rhs );

	void			ninjaShoebox( ClapTrap const & target );
	void			ninjaShoebox( ScavTrap const & target );
	void			ninjaShoebox( FragTrap const & target );
	void			ninjaShoebox( NinjaTrap const & target );
};

#endif
