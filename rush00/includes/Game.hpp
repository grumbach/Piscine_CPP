/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:34:30 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 12:36:35 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "settings.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Star.hpp"
#include "Menu.hpp"

class Game {

public:

	Game( void );
	Game( Game const & src );
	~Game();

	Game &				operator=( Game const & rhs );

	void				play_game();

private:

	void				_init_game();
	bool				_get_input();
	void				_update_positions();
	bool				_check_collision();
	void				_redraw_window();
	std::string			_get_score_str();

	Menu				_menu;
	Player				_player;
	Player				_player2;
	Enemy				_enemies[ENEMIES];
	Star				_stars[STARS];

	int					_window_width;
	int					_window_height;
	unsigned int		_score;
	int					_number_of_players;

};

#endif
