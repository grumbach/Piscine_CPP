/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:54 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 17:14:58 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( void );
	ScavTrap( std::string const & name );
	ScavTrap( ScavTrap const & src );
	~ScavTrap();

	ScavTrap &		operator=( ScavTrap const & rhs );

	void			challengeNewcomer(std::string const & target);
};

#endif
