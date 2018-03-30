/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:26:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 19:37:36 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int			main(int ac, char **av)
{
	Game	game;

	game.init_game();

	game.play_game();

	game.end_game();

	return (0);
}
