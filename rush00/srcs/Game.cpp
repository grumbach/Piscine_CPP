/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:38:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 21:34:36 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( void )
{ }

Game::Game( Game const & src )
{ (void)src; }

Game::~Game()
{ }

Game &			Game::operator=( Game const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** Public
*/

void			Game::init_game()
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
	init_pair(ENEMIES_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(STARS_COLOR, COLOR_BLUE, COLOR_BLACK);

	this->_window_height = LINES;
	this->_window_width = COLS;

	this->player.pos_y = LINES - 10;
	this->player.pos_x = COLS / 2;
}

void			Game::play_game()
{
	_show_menu("< FT_RETRO >     insert coin");

	while (42)
	{
		if (!_get_input())
			break;
		_update_positions();
		_redraw_window();
	}
}

void			Game::end_game()
{
	endwin();
	exit(0);
}

/*
** Private
*/

void			Game::_show_menu( std::string const & message )
{
	int			ch = getch();

	clear();
	box(stdscr, 0, 0);
	mvprintw(this->_window_height / 2, this->_window_width / 3, message.c_str());
	refresh();
	//press RETURN to start
	while (ch != KEY_RETURN)
	{
		ch = getch();
		if (ch == KEY_ESC)
			this->end_game();
	}
}


inline bool		Game::_get_input()
{
	int			ch = getch();


	if (ch == KEY_ESC)
		return false;
	else if (ch == KEY_DOWN)
		this->player.pos_y++;
	else if (ch == KEY_UP)
		this->player.pos_y--;
	else if (ch == KEY_LEFT)
		this->player.pos_x--;
	else if (ch == KEY_RIGHT)
		this->player.pos_x++;
	else if (ch == KEY_SPACE)
		this->player.shoot_missile();

	if (this->_window_width != COLS || this->_window_height != LINES)
	{
		if (this->_window_width > COLS || this->_window_height > LINES)
			_show_menu("Space distortion detected, BIG CRUNCH!");
		else
			_show_menu("Space distortion detected, BIG BANG!");
		return false;
	}
	return true;
}

inline void		Game::_update_positions()
{
	;
}

inline void		Game::_move_ufo( A_ufo & )
{
	;
}

void			Game::_redraw_window()
{
	clear();
	//draw all;

	mvaddch(this->player.pos_y, this->player.pos_x, \
		PLAYER_SKIN | A_BOLD | COLOR_PAIR(PLAYER_COLOR));

	refresh();
}
