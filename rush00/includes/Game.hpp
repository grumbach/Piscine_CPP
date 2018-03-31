/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:34:30 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:35:45 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "settings.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Star.hpp"

class Game {

public:

	Game( void );
	Game( Game const & src );
	~Game();

	Game &			operator=( Game const & rhs );

	void			play_game();
	void			end_game();


	Player			player;
	Enemy			enemies[ENEMIES];
	Star			stars[STARS];

private:

	void			_show_menu( std::string const & message );

	bool			_get_input();
	void			_update_positions();
	void				_move_ufo( A_ufo & );
	void			_redraw_window();

	static int		_window_width;
	static int		_window_height;

};

#endif
