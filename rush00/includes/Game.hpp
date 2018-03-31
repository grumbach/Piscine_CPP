/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:34:30 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 18:03:21 by agrumbac         ###   ########.fr       */
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

	bool				_get_input();
	void				_update_positions();
	bool				_check_collision();
	void				_redraw_window();
	std::string			_get_score_str();

	Menu				_menu;
	Player				_player;
	Enemy				_enemies[ENEMIES];
	Star				_stars[STARS];

	int					_window_width;
	int					_window_height;
	unsigned int		_score;

};

#endif
