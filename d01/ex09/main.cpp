/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:39:48 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/23 18:49:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int				main(int ac, char **av)
{
	if (ac <= 1)
		std::cerr << "logger: please give me at least one arg..." << std::endl;

	char			**av2 = av;
	char			buf[100];
	std::time_t		t = std::time(nullptr);
	std::string		timestamp("[error getting time]");

	if (std::strftime(buf, sizeof(buf), "%Y%m%d_%Hh", std::localtime(&t)))
		timestamp = buf;

	Logger			logger("log_file_" + timestamp + ".log");

	while (*++av)
		logger.log("console", *av);

	while (*++av2)
		logger.log("file", *av2);

	return (0);
}
