/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:24:08 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/20 19:29:00 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

unsigned int	Pony::_ponies_alive()
{
	return (Pony::_living_ponies);
}

void			Pony::show ()
{
	std::string		colors[7] = {"\e[31m", "\e[32m", "\e[33m", "\e[34m", \
								"\e[35m", "\e[36m", "\e[37m"};
	std::string		s = colors[this->hair_color % 7];
	std::string		h = colors[this->skin_color % 7];

	std::cout << h << "    >>\\." 						<< std::endl;
	std::cout << s << "   /" << "\e[5m"<< "_ " << "\e[0m" << h << " )`." << std::endl;
	std::cout << s << "  /  _)" << h << "`^)`. "<< s <<"  _.---. " << h << "_" << std::endl;
	std::cout << s << " (_,' \\  " << h << "`^-)"<< s <<"\"\"      `." << h << "\\" << std::endl;
	std::cout << s << "       |              | " << h << "\\" 	<< std::endl;
	std::cout << s << "       \\              / " << h << "|" 	<< std::endl;
	std::cout << s << "      / \\  /.___.'\\  (" << h << "\\ (_" << std::endl;
	std::cout << s << "     < ,\"||     \\ |`. \\" << h << "`-'" << std::endl;
	std::cout << s << "      \\\\ ()      )|  )/" 		<< std::endl;
	std::cout << "      |_>|>     /_] //" 				<< std::endl;
	std::cout << "        /_]        /_]" 				<< std::endl;
	std::cout << "\e[0m";
}

Pony::Pony (int skin, int hair)
	: skin_color(skin)
	, hair_color(hair)
{
	Pony::_living_ponies++;
}

Pony::~Pony ()
{
	Pony::_living_ponies--;
}

unsigned int		Pony::_living_ponies = 0;
