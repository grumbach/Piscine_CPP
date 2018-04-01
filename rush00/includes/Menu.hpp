/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:07:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:43:09 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.hpp"

#ifndef MENU_H
# define MENU_H

class Menu {

public:

	Menu( void );
	Menu( Menu const & src );
	virtual ~Menu();

	Menu &			operator=( Menu const & rhs );

	void			show_top_bar( int const hp, int const hp2, std::string score) const;

	int				welcome( void ) const;
	void			game_over( std::string const score ) const;

private:

	int				_wait_for_input( void ) const;

};

#endif
