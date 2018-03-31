/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:38:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 12:44:12 by agrumbac         ###   ########.fr       */
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
	init_pair(ENEMIES_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(STARS_COLOR, COLOR_BLUE, COLOR_BLACK);

	std::srand(std::time(nullptr));

	this->_window_height = LINES;
	this->_window_width = COLS;

	this->player.pos_y = LINES - 10;
	this->player.pos_x = COLS / 2;
}

Game::Game( Game const & src )
{
	(void)src;
}

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

void			Game::play_game()
{
	_show_menu("< FT_RETRO >     insert coin");

	while (this->player.hp)
	{
		if (!_get_input())
			break;
		_update_positions();
		_check_collision();
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
	else if (ch == KEY_DOWN && this->player.pos_y < LINES - 2)
		this->player.pos_y++;
	else if (ch == KEY_UP && this->player.pos_y > 1)
		this->player.pos_y--;
	else if (ch == KEY_LEFT && this->player.pos_x > 1)
		this->player.pos_x--;
	else if (ch == KEY_RIGHT && this->player.pos_x < COLS - 2)
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
	A_ufo		*ufo;

	//TODO beautify this
	for (size_t i = 0; i < STARS; i++)
	{
		ufo = &this->stars[i];
		ufo->move();
	}
	for (size_t i = 0; i < ENEMIES; i++)
	{
		ufo = &this->enemies[i];
		ufo->move();
	}
	for (size_t i = 0; i < MISSILES; i++)
	{
		ufo = &this->player.missiles[i];
		ufo->move();
	}
}

bool					Game::_check_collision()
{
	for (size_t i = 0; i < ENEMIES; i++)
		if (this->enemies[i].hp && \
		this->player.pos_x == this->enemies[i].pos_x && \
		this->player.pos_y == this->enemies[i].pos_y)
		{
			this->player.hp--;
			this->player.skin = '&';
			break ;
		}
	for (size_t i = 0; i < MISSILES; i++)
	{	
		for (size_t j = 0; this->player.missiles[i].hp && this->enemies[i].hp && \
		j < ENEMIES; j++)
			if (this->enemies[j].hp && \
			this->enemies[j].pos_x == this->player.missiles[i].pos_x && \
			this->enemies[j].pos_y == this->player.missiles[i].pos_y)
			{
				this->enemies[j].hp--;
				this->player.missiles[i].hp--;
				this->player.missiles[i].pos_x = -1;
				this->player.missiles[i].pos_y = -1;				
				this->enemies[j].skin = '&';
				break;
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
		ufo = &this->stars[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	for (size_t i = 0; i < ENEMIES; i++)
	{
		ufo = &this->enemies[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	for (size_t i = 0; i < MISSILES; i++)
	{
		ufo = &this->player.missiles[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	ufo = &this->player;
	mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);

	refresh();
}