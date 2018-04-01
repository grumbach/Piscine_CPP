/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <stmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 00:36:14 by stmartin          #+#    #+#             */
/*   Updated: 2018/04/01 17:41:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"

Boss::Boss( void ) : A_spacecraft(50, 0)
{
	this->_side_move = 0;
	this->_change_side = 10;
	this->pos_x = COLS / 2;
	this->pos_y = 3;
	for (size_t i = 0; i < BOSS_MISSILES; i++)
	{
		this->missiles[i].direction = ENEMIES_DIRECTION;
		this->missiles[i].skin = EMISSILES_SKIN;
	}
}

Boss::Boss( Boss const & src ) : A_spacecraft(src)
{
	*this = src;
}

Boss::~Boss()
{ }


Boss &			Boss::operator=( Boss const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** Features
*/

void			Boss::check_collision( Player & player )
{
	const int hit_box_x_end = this->pos_x + 32;
	const int hit_box_y_end = this->pos_y + 6;

	//boss and player
	if (this->pos_x < player.pos_x && player.pos_x < hit_box_x_end && \
		this->pos_y < player.pos_y && player.pos_y < hit_box_y_end)
	{
		player.take_damage(1);
		this->take_damage(1);
	}

	//boss and player missiles
	for (size_t i = 0; i < MISSILES; i++)
	{
		if (this->pos_x < player.missiles[i].pos_x && player.missiles[i].pos_x < hit_box_x_end && \
			this->pos_y < player.missiles[i].pos_y && player.missiles[i].pos_y < hit_box_y_end)
		{
			player.missiles[i].take_damage(1);
			this->take_damage(1);
		}
	}
}

/*
** this->_side_move 1:RIGHT 2:LEFT
*/

void			Boss::awaken( int const score )
{
	this->hp = score;
	this->pos_y = 3;
	this->pos_x = std::rand() % COLS - 42;
}

void			Boss::move()
{
	if (this->can_move())
	{
		if (this->_side_move == 1 && this->pos_x + 39 < COLS)
			this->pos_x++;
		else if (this->_side_move == 2 && this->pos_x > 0)
			this->pos_x--;
		this->_change_side--;

		if (!this->_change_side)
		{
			if (std::rand() % 2)
				this->_side_move = 1;
			else
				this->_side_move = 2;
			this->_change_side = 10;
		}

		if (!(std::rand() % ENEMIES_RANK / 8))
			this->_shoot_missile();
	}
}

void			Boss::_shoot_missile()
{
	static const int canon_x[5] = {7, 14, 18, 22, 29};
	static const int canon_y[5] = {8, 10, 12, 10, 8};
	int missile_pos;

	for (size_t i = 0; i < BOSS_MISSILES; i++)
	{
		if (this->missiles[i].hp == 0)
		{
			this->missiles[i].hp = 1;
			missile_pos = std::rand() % 5;

			this->missiles[i].pos_y = this->pos_y + canon_y[missile_pos];
			this->missiles[i].pos_x = this->pos_x + canon_x[missile_pos];
			break;
		}
	}
}

void			Boss::draw()
{
	attron(COLOR_PAIR(MISSILES_COLOR));
	mvprintw(this->pos_y, this->pos_x, "             V   ___   V");
	mvprintw(this->pos_y + 1, this->pos_x, "            _^_ /___\\ _^_");
	mvprintw(this->pos_y + 2, this->pos_x, "(._________| \" |[   ]| \" |_________.)");
	mvprintw(this->pos_y + 3, this->pos_x, " \\_\\______ | ' ||___|| ' | ______/_/");
	mvprintw(this->pos_y + 4, this->pos_x, "    \\______'(O)'(   )'(O)'______/");
	mvprintw(this->pos_y + 5, this->pos_x, "      YY    \\____\\_/____/    YY");
	mvprintw(this->pos_y + 6, this->pos_x, "      ||     YY \\\\_// YY     ||");
	mvprintw(this->pos_y + 7, this->pos_x, "       |     || [ V ] ||     |");
	mvprintw(this->pos_y + 8, this->pos_x, "              | [ ' ] |");
	mvprintw(this->pos_y + 9, this->pos_x, "              ' [ ' ] '");
	mvprintw(this->pos_y + 10, this->pos_x, "                 [_]");
	mvprintw(this->pos_y + 11, this->pos_x, "                  Y");
	attroff(COLOR_PAIR(MISSILES_COLOR));
}

void			Boss::draw_missiles()
{
	for (size_t j = 0; j < BOSS_MISSILES; j++)
	{
		if (this->missiles[j].hp == 1)
		{
			mvaddch(this->missiles[j].pos_y, this->missiles[j].pos_x, EMISSILES_SKIN);
		}
	}
}
