/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:06:58 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/31 11:35:23 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include <iostream>

#ifndef SETTING_H
# define SETTING_H

# define MISSILES			42
# define ENEMIES			10
# define STARS				20

# define DEFAULT_HP			3

# define PLAYER_COLOR		1
# define MISSILES_COLOR		2
# define ENEMIES_COLOR		3
# define STARS_COLOR		4

# define MISSILES_VELOCITY	200
# define ENEMIES_VELOCITY	300
# define STARS_VELOCITY		100

# define PLAYER_SKIN		('^' | A_BOLD | COLOR_PAIR(PLAYER_COLOR))
# define MISSILES_SKIN		('\'' | COLOR_PAIR(MISSILES_COLOR))
# define ENEMIES_SKIN		('H' | COLOR_PAIR(ENEMIES_COLOR))
# define STARS_SKIN			('.' | COLOR_PAIR(STARS_COLOR))

# define KEY_ESC			27
# define KEY_SPACE			32
# define KEY_RETURN			10

#endif
