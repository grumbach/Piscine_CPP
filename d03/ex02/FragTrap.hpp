/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:53:29 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 17:43:02 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap( void );
	FragTrap( std::string const & name );
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap &		operator=( FragTrap const & rhs );

	void			vaulthunter_dot_exe(std::string const & target);
};

#endif
