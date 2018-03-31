/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:38:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 20:44:14 by agrumbac         ###   ########.fr       */
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
	init_pair(MISSILES_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(ENEMIES_COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(EMISSILES_COLOR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(STARS_COLOR, COLOR_WHITE, COLOR_BLACK);

	std::srand(std::time(nullptr));

	this->_window_height = LINES;
	this->_window_width = COLS;
	this->_score = 0;

	this->_player.pos_y = LINES - 10;
	this->_player.pos_x = COLS / 2;

	for (size_t i = 0; i < STARS; i++)
	{
		this->_stars[i].pos_x = RANDOM_X_SPAWN;
		this->_stars[i].pos_y = RANDOM_Y_SPAWN;
	}
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
	if (!this->_menu.welcome())
		return ;

	while (this->_player.hp > 0)
	{
		if (!_get_input())
			break;
		_update_positions();
		_check_collision();
		_redraw_window();
	}

	if (this->_player.hp <= 0)
		this->_menu.game_over(std::string("Score: ") + this->_get_score_str());
}

/*
** ------------------------------ Private --------------------------------------
*/

inline bool		Game::_get_input()
{
	int			ch = getch();

	if (ch == KEY_ESC)
		return false;
	else if (ch == KEY_DOWN && this->_player.pos_y < LINES - 2)
		this->_player.pos_y++;
	else if (ch == KEY_UP && this->_player.pos_y > 1)
		this->_player.pos_y--;
	else if (ch == KEY_LEFT && this->_player.pos_x > 1)
		this->_player.pos_x--;
	else if (ch == KEY_RIGHT && this->_player.pos_x < COLS - 2)
		this->_player.pos_x++;
	else if (ch == KEY_SPACE)
		this->_player.shoot_missile();

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
	A_ufo		*ufo;

	//TODO beautify this
	for (size_t i = 0; i < STARS; i++)
	{
		ufo = &this->_stars[i];
		ufo->move();
	}
	for (size_t i = 0; i < (this->_score / 4) + 8 && i < ENEMIES; i++)
	{
		ufo = &this->_enemies[i];
		ufo->move();
		for (size_t j = 0; j < ENEMIES_MISSILES; j++)
		{
			ufo = &this->_enemies[i].missiles[j];
			ufo->move();
		}
	}
	for (size_t i = 0; i < MISSILES; i++)
	{
		ufo = &this->_player.missiles[i];
		ufo->move();
	}
}

bool					Game::_check_collision()
{
	for (size_t i = 0; i < ENEMIES; i++)
	{
		if (this->_player.pos_x == this->_enemies[i].pos_x && \
			this->_player.pos_y == this->_enemies[i].pos_y)
		{
			this->_player.hp--;
			this->_enemies[i].hp--;
			break ;
		}
		for (size_t j = 0; j < ENEMIES_MISSILES; j++)
		{
			if (this->_player.pos_x == this->_enemies[i].missiles[j].pos_x && \
				this->_player.pos_y == this->_enemies[i].missiles[j].pos_y)
			{
				this->_player.hp--;
				this->_enemies[i].missiles[j].hp--;
				this->_enemies[i].missiles[j].pos_x = -1;
				this->_enemies[i].missiles[j].pos_y = -1;
				break ;
			}
		}
	}
	for (size_t i = 0; i < MISSILES; i++)
	{
		for (size_t j = 0; this->_player.missiles[i].hp && \
			this->_enemies[j].hp && j < ENEMIES; j++)
		{
			if (this->_enemies[j].pos_x == this->_player.missiles[i].pos_x && \
				this->_enemies[j].pos_y == this->_player.missiles[i].pos_y)
			{
				this->_score++;
				this->_enemies[j].hp--;
				this->_player.missiles[i].hp--;
				this->_player.missiles[i].pos_x = -1;
				this->_player.missiles[i].pos_y = -1;
				break;
			}
		}
	}
	return (false);
}

void			Game::_redraw_window()
{
	A_ufo		*ufo;

	clear();

	//TODO beautify this
	for (size_t i = 0; i < STARS; i++)
	{
		ufo = &this->_stars[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	for (size_t i = 0; i < ENEMIES; i++)
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
	}
	ufo = &this->_player;
	mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);

	for (int i = 0; i < this->_player.hp; i++)
	{
		//display HP
		attron(COLOR_PAIR(MISSILES_COLOR));
		mvprintw(0, i * 3, "<3");
		attroff(COLOR_PAIR(MISSILES_COLOR));

		//diplay score
		attron(COLOR_PAIR(PLAYER_COLOR));
		mvprintw(0, COLS / 2, this->_get_score_str().c_str());
		attroff(COLOR_PAIR(PLAYER_COLOR));
	}

	refresh();
}

std::string			Game::_get_score_str()
{
	std::ostringstream s;
	s << this->_score;
	return s.str();
}
