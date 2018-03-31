/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:34:30 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 16:49:39 by agrumbac         ###   ########.fr       */
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

	Game &				operator=( Game const & rhs );

	void				play_game();
	void				end_game();


	Player				player;
	Enemy				enemies[ENEMIES];
	Star				stars[STARS];

private:

	void				_show_menu( std::string const & message );

	bool				_get_input();
	void				_update_positions();
	bool				_check_collision();
	void				_redraw_window();

	int					_window_width;
	int					_window_height;
	unsigned int		_score;

};

#endif
