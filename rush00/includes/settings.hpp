/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:06:58 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 20:14:07 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <sstream>

#ifndef SETTING_H
# define SETTING_H

# define MISSILES			42
# define ENEMIES			20
# define ENEMIES_MISSILES	3
# define STARS				42

# define ENEMIES_RANK		10	//less means tougher enemies

# define DEFAULT_HP			3

# define PLAYER_COLOR		1
# define MISSILES_COLOR		2
# define ENEMIES_COLOR		3
# define EMISSILES_COLOR	4
# define STARS_COLOR		5

# define MISSILES_DELAY		42
# define ENEMIES_DELAY		300
# define STARS_DELAY		90

# define RANDOM_X_SPAWN		(std::rand() % (COLS - 1))
# define RANDOM_Y_SPAWN		(std::rand() % (LINES - 1))
# define RANDOM_SPAWN_DELAY	(std::rand() % 42)

# define PLAYER_SKIN		('^' | A_BOLD | COLOR_PAIR(PLAYER_COLOR))
# define MISSILES_SKIN		('\'' | A_BOLD | COLOR_PAIR(MISSILES_COLOR))
# define EMISSILES_SKIN		('*' | A_BOLD |COLOR_PAIR(EMISSILES_COLOR))
# define ENEMIES_SKIN		('V' | A_BOLD | COLOR_PAIR(ENEMIES_COLOR))
# define STARS_SKIN			('.' | A_DIM | COLOR_PAIR(STARS_COLOR))
# define EXPLOSION_SKIN		('@' | A_BOLD | COLOR_PAIR(MISSILES_COLOR))

# define KEY_ESC			27
# define KEY_SPACE			32
# define KEY_RETURN			10

#endif
