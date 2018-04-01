/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:07:58 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 21:47:40 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"

Menu::Menu( void )
{ }

Menu::Menu( Menu const & src )
{ (void)src; }

Menu::~Menu()
{ }


Menu &			Menu::operator=( Menu const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** GUI
*/

void			Menu::show_top_bar( int const hp, int const hp2, \
				std::string score) const
{
	//display player's HP
	for (int i = 0; i < hp; i++)
	{
		attron(COLOR_PAIR(MISSILES_COLOR));
		mvprintw(0, i * 3, "<3");
		attroff(COLOR_PAIR(MISSILES_COLOR));
	}

	//display player2's HP
	for (int i = 0; i < hp2; i++)
	{
		attron(COLOR_PAIR(MISSILES_COLOR));
		mvprintw(0, (COLS - 2 - i * 3), "<3");
		attroff(COLOR_PAIR(MISSILES_COLOR));
	}

	//diplay score
	attron(COLOR_PAIR(PLAYER_COLOR));
	mvprintw(0, COLS / 2, score.c_str());
	attroff(COLOR_PAIR(PLAYER_COLOR));
}

/*
** Menus
*/

int			Menu::welcome() const
{
	clear();
	attron(COLOR_PAIR(PLAYER_COLOR));
	mvprintw(LINES / 3 + 0, COLS / 4, "   __________  ___  _____________  ____  ");
	mvprintw(LINES / 3 + 1, COLS / 4, "  / __/_  __/ / _ \\/ __/_  __/ _ \\/ __ \\");
	mvprintw(LINES / 3 + 2, COLS / 4, " / _/  / /   / , _/ _/  / / / , _/ /_/ / ");
	mvprintw(LINES / 3 + 3, COLS / 4, "/_/   /_/___/_/|_/___/ /_/ /_/|_|\\____/  ");
	mvprintw(LINES / 3 + 4, COLS / 4, "       /___/                             ");
	mvprintw(LINES / 3 + 7, COLS / 4, "     1: Single Player    2: Multiplayer");
	mvprintw(LINES / 3 + 10, COLS / 5,	"                           *     .--.");
	mvprintw(LINES / 3 + 11, COLS / 5,	"                                / /  `");
	mvprintw(LINES / 3 + 12, COLS / 5,	"               +               | |");
	mvprintw(LINES / 3 + 13, COLS / 5,	"                      '         \\ \\__,");
	mvprintw(LINES / 3 + 14, COLS / 5,	"                  *          +   '--'  *");
	mvprintw(LINES / 3 + 15, COLS / 5,	"                      +   /\\");
	mvprintw(LINES / 3 + 16, COLS / 5,	"         +              .'  '.   *");
	mvprintw(LINES / 3 + 17, COLS / 5,	"                *      /======\\      +");
	mvprintw(LINES / 3 + 18, COLS / 5,	"                      ;:.  _   ;");
	mvprintw(LINES / 3 + 19, COLS / 5,	"                      |:. (_)  |");
	mvprintw(LINES / 3 + 20, COLS / 5,	"                      |:.  _   |");
	mvprintw(LINES / 3 + 21, COLS / 5,	"            +         |:. (_)  |          *");
	mvprintw(LINES / 3 + 22, COLS / 5,	"                      ;:.      ;");
	mvprintw(LINES / 3 + 23, COLS / 5,	"                    .' \\:.    / `.");
	mvprintw(LINES / 3 + 24, COLS / 5,	"                   / .-'':._.'`-. \\");
	mvprintw(LINES / 3 + 25, COLS / 5,	"                   |/    /||\\    \\|");
	mvprintw(LINES / 3 + 26, COLS / 5,	"                 _..--\"\"\"````\"\"\"--.._");
	mvprintw(LINES / 3 + 27, COLS / 5,	"           _.-'``                    ``'-._");
	mvprintw(LINES / 3 + 28, COLS / 5,	"         -'                               '-");
	box(stdscr, 0, 0);
	attroff(COLOR_PAIR(PLAYER_COLOR));
	refresh();

	for (int ch = -1;; ch = this->_wait_for_input())
	{
		if (ch == KEY_ESC)
			return 0;
		if (ch == '1')
			return 1;
		if (ch == '2')
			return 2;
	}
	return 1;
}

void			Menu::game_over( std::string const score ) const
{
	clear();
	attron(COLOR_PAIR(MISSILES_COLOR));
	mvprintw(LINES / 3 + 0, COLS / 5, "  ________   __  _______  ____ _   _________  ");
	mvprintw(LINES / 3 + 1, COLS / 5, " / ___/ _ | /  |/  / __/ / __ \\ | / / __/ _ \\");
	mvprintw(LINES / 3 + 2, COLS / 5, "/ (_ / __ |/ /|_/ / _/  / /_/ / |/ / _// , _/ ");
	mvprintw(LINES / 3 + 3, COLS / 5, "\\___/_/ |_/_/  /_/___/  \\____/|___/___/_/|_|  ");
	attroff(COLOR_PAIR(MISSILES_COLOR));
	mvprintw(LINES / 3 + 6, COLS / 6, score.c_str());
	attron(COLOR_PAIR(PLAYER_COLOR));
	mvprintw(LINES / 3 + 9, COLS / 6, "      .        See you space cowboy...          ,              ");
	mvprintw(LINES / 3 + 11, COLS / 6, ".                                         *       +           ");
	mvprintw(LINES / 3 + 12, COLS / 6, "*   .                  .        '                  |          ");
	mvprintw(LINES / 3 + 13, COLS / 6, ".         .                       .-.,=\"``\"=.    - o -      ");
	mvprintw(LINES / 3 + 14, COLS / 6, "                                  '=/_       \\     |         ");
	mvprintw(LINES / 3 + 15, COLS / 6, ".              .               *   |  '=._    |               ");
	mvprintw(LINES / 3 + 16, COLS / 6, ".     .                             \\     `=./`,             ");
	mvprintw(LINES / 3 + 17, COLS / 6, " .          .          *  ,      .   '=.__.=' `='             ");
	mvprintw(LINES / 3 + 18, COLS / 6, ".                    .          +                             ");
	mvprintw(LINES / 3 + 19, COLS / 6, "    .         ,                     O      *        '         ");
	mvprintw(LINES / 3 + 20, COLS / 6, ".                 .                                           ");
	mvprintw(LINES / 3 + 21, COLS / 6, "           .                              .                   ");
	mvprintw(LINES / 3 + 22, COLS / 6, "    .      ,  *              .                                ");
	mvprintw(LINES / 3 + 23, COLS / 6, "  ,             .                          .                  ");
	mvprintw(LINES / 3 + 24, COLS / 6, ".    ,       ,             .     *      .               .     ");
	mvprintw(LINES / 3 + 25, COLS / 6, "        .                             ,                       ");
	mvprintw(LINES / 3 + 26, COLS / 6, ".       ,      ,             .            .    ,              ");
	mvprintw(LINES / 3 + 27, COLS / 6, "      \\          .                         .                 ");
	mvprintw(LINES / 3 + 28, COLS / 6, "____^/\\___^--____/\\____O______________/\\/\\---/\\__________");
	mvprintw(LINES / 3 + 29, COLS / 6, "/\\^   ^  ^    ^                  ^^ ^  '\\ ^          ^      ");
	mvprintw(LINES / 3 + 30, COLS / 6, "--           -            --  -      -         ---  __        ");
	mvprintw(LINES / 3 + 31, COLS / 6, "--  __                      ___--  ^  ^                       ");
	box(stdscr, 0, 0);
	attroff(COLOR_PAIR(PLAYER_COLOR));
	refresh();
	while (this->_wait_for_input() != KEY_ESC);
}

int				Menu::_wait_for_input( void ) const
{
	int			ch = getch();

	while (ch == -1)
		ch = getch();
	return (ch);
}
