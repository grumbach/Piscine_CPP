/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:38:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:52:45 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( void )
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	start_color();

	init_pair(PLAYER_COLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(PLAYER2_COLOR, COLOR_CYAN, COLOR_BLACK);
	init_pair(MISSILES_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(ENEMIES_COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(EMISSILES_COLOR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(STARS_COLOR, COLOR_WHITE, COLOR_BLACK);

	std::srand(std::time(nullptr));

	this->_init_game();
	this->_window_height = LINES;
	this->_window_width = COLS;
	this->_score = 0;
}

Game::Game( Game const & src )
{
	(void)src;
}

Game::~Game()
{
	endwin();
}

Game &			Game::operator=( Game const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** ------------------------------- Public --------------------------------------
*/

void			Game::play_game()
{
	if (!(this->_number_of_players = this->_menu.welcome()))
		return ;
	if (this->_number_of_players == 1)
		this->_player2.take_damage(DEFAULT_HP);

	while (this->_player.hp > 0 || this->_player2.hp > 0)
	{
		if (!_get_input())
			break;
		_update_positions();
		_check_collision(this->_player);
		_check_collision(this->_player2);
		_redraw_window();
	}

	if (this->_player.hp <= 0 && this->_player2.hp <= 0)
		this->_menu.game_over(std::string("Score: ") + this->_get_score_str());
}

/*
** ------------------------------ Private --------------------------------------
*/

void			Game::_init_game()
{
	this->_player.pos_y = LINES - 10;
	this->_player.pos_x = COLS / 2;

	this->_player2.pos_y = LINES - 15;
	this->_player2.pos_x = COLS / 2;

	for (size_t i = 0; i < STARS; i++)
	{
		this->_stars[i].pos_x = RANDOM_X_SPAWN;
		this->_stars[i].pos_y = RANDOM_Y_SPAWN;
	}

	this->_player.set_bindings('s', 'w', 'a', 'd', KEY_SPACE);
	this->_player2.set_bindings(KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_ENDL);

	this->_player2.skin = PLAYER2_SKIN;
}

inline bool		Game::_get_input()
{
	int			ch = getch();

	if (ch == KEY_ESC)
		return false;
	if (this->_player.hp > 0)
		this->_player.apply_input(ch);
	if (this->_player2.hp > 0)
		this->_player2.apply_input(ch);

	if (this->_window_width != COLS || this->_window_height != LINES)
	{
		if (this->_window_width > COLS || this->_window_height > LINES)
			this->_menu.game_over("Space distortion detected, BIG CRUNCH! Score: -42");
		else
			this->_menu.game_over("Space distortion detected, BIG BANG! Score: -42");
		return false;
	}
	return true;
}

inline void		Game::_update_positions()
{
	for (size_t i = 0; i < STARS; i++)
		this->_stars[i].move();
	if (this->_boss.hp)
	{
		this->_boss.move();
		for (size_t j = 0; j < BOSS_MISSILES; j++)
			this->_boss.missiles[j].move();
	}
	for (size_t i = 0; i < SPAWNED_ENEMIES(this->_score); i++)
	{
		this->_enemies[i].move();
		for (size_t j = 0; j < ENEMIES_MISSILES; j++)
			this->_enemies[i].missiles[j].move();
	}
	for (size_t i = 0; i < MISSILES; i++)
	{
		this->_player.missiles[i].move();
		this->_player2.missiles[i].move();
	}
	this->_bonus.move();
	if (this->_boss.hp <= 0 && this->_score && this->_score % BOSS_SPAWN == 0)
		this->_boss.awaken(this->_score);
}

/*
**	_check_collision checks :
**
** 	player with enemies
**
**	for (enemies)
**		player with enemy missiles
**		enemy with player missiles
**
**	if (boss is alive)
**		boss with player && boss with player missiles
**		player with boss missiles
*/

inline void		Game::_check_collision( Player & player )
{
	if (player.hp > 0)
	{
		for (size_t i = 0; i < SPAWNED_ENEMIES(this->_score); i++)
		{
			player.check_collision(FREEDOM(&this->_enemies[i]), 1);
			player.check_collision(FREEDOM(&this->_enemies[i].missiles), \
				ENEMIES_MISSILES);
			this->_score += this->_enemies[i].check_collision(\
				FREEDOM(&player.missiles), MISSILES);
		}

		if (this->_boss.hp > 0)
		{
			this->_boss.check_collision(player);
			player.check_collision(FREEDOM(&this->_boss.missiles), BOSS_MISSILES);
		}
		if (this->_bonus.hp > 0)
			this->_bonus.check_collision(player);
	}
}

inline void		Game::_redraw_window()
{
	A_ufo		*ufo;

	erase();

	//TODO beautify this
	for (size_t i = 0; i < STARS; i++)
	{
		ufo = &this->_stars[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	if (this->_boss.hp)
	{
		this->_boss.draw();
		this->_boss.draw_missiles();
	}
	for (size_t i = 0; i < SPAWNED_ENEMIES(this->_score); i++)
	{
		ufo = &this->_enemies[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
		for (size_t j = 0; j < ENEMIES_MISSILES; j++)
		{
			ufo = &this->_enemies[i].missiles[j];
			mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
		}
	}
	for (size_t i = 0; i < MISSILES; i++)
	{
		ufo = &this->_player.missiles[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
		ufo = &this->_player2.missiles[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	mvaddch(this->_bonus.pos_y, this->_bonus.pos_x, this->_bonus.skin);
	ufo = &this->_player;
	mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	ufo = &this->_player2;
	mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);

	this->_menu.show_top_bar(this->_player.hp, this->_player2.hp, \
		this->_get_score_str());
	refresh();
}

std::string			Game::_get_score_str() const
{
	std::ostringstream s;
	s << this->_score;
	return s.str();
}
