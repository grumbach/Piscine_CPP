/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:38:56 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/01 15:42:41 by stmartin         ###   ########.fr       */
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
	init_pair(STARS_COLOR, COLOR_BLACK, COLOR_BLACK);

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
		_check_collision();
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

	this->_player.set_bindings(KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_ENDL);
	this->_player2.set_bindings('s', 'w', 'a', 'd', KEY_SPACE);

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
	A_ufo		*ufo;

	//TODO beautify this
	for (size_t i = 0; i < STARS; i++)
	{
		ufo = &this->_stars[i];
		ufo->move();
	}
	if (this->_boss.hp)
	{
		ufo = &this->_boss;
		ufo->move();
		for (size_t j = 0; j < BOSS_MISSILES; j++)
		{
			ufo = &this->_boss.missiles[j];
			ufo->move();
		}
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
		ufo = &this->_player2.missiles[i];
		ufo->move();
	}
}

//TODO beautify this.. uhm no.. make this watchable
//super evil function....... MUUHAHAHAHAAHAHAHAHAHAHAH! >:D-
//only check for collison on objects that ARE ALIVE!!
bool					Game::_check_collision()
{
	for (size_t i = 0; i < ENEMIES; i++)
	{
		if (this->_player.pos_x == this->_enemies[i].pos_x && \
			this->_player.pos_y == this->_enemies[i].pos_y)
		{
			this->_player.take_damage(1);
			this->_enemies[i].take_damage(1);
			break ;
		}
		if (this->_player2.pos_x == this->_enemies[i].pos_x && \
			this->_player2.pos_y == this->_enemies[i].pos_y)
		{
			this->_player2.take_damage(1);
			this->_enemies[i].take_damage(1);
			break ;
		}
		for (size_t j = 0; j < ENEMIES_MISSILES; j++)
		{
			if (this->_player.pos_x == this->_enemies[i].missiles[j].pos_x && \
				this->_player.pos_y == this->_enemies[i].missiles[j].pos_y)
			{
				this->_player.take_damage(1);
				this->_enemies[i].missiles[j].take_damage(1);
				break ;
			}
		}
		for (size_t j = 0; j < ENEMIES_MISSILES; j++)
		{
			if (this->_player2.pos_x == this->_enemies[i].missiles[j].pos_x && \
				this->_player2.pos_y == this->_enemies[i].missiles[j].pos_y)
			{
				this->_player2.take_damage(1);
				this->_enemies[i].missiles[j].take_damage(1);
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
				this->_enemies[j].take_damage(1);
				this->_player.missiles[i].take_damage(1);
				break;
			}
		}
		for (size_t j = 0; this->_player2.missiles[i].hp && \
			this->_enemies[j].hp && j < ENEMIES; j++)
		{
			if (this->_enemies[j].pos_x == this->_player2.missiles[i].pos_x && \
				this->_enemies[j].pos_y == this->_player2.missiles[i].pos_y)
			{
				this->_score++;
				this->_enemies[j].take_damage(1);
				this->_player2.missiles[i].take_damage(1);
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
	if (this->_boss.hp)
	{
		this->_boss.draw();
		this->_boss.draw_missiles();
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
		ufo = &this->_player2.missiles[i];
		mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	}
	ufo = &this->_player;
	mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);
	ufo = &this->_player2;
	mvaddch(ufo->pos_y, ufo->pos_x, ufo->skin);

	this->_menu.show_top_bar(this->_player.hp, this->_player2.hp, \
		this->_get_score_str());
	if (this->_score && this->_score % BOSS_SPAWN == 0)
		this->_boss.hp = 42;
	refresh();
}

std::string			Game::_get_score_str()
{
	std::ostringstream s;
	s << this->_score;
	return s.str();
}
