/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:52:44 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/23 22:03:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	cat_stream(std::istream &stream)
{
	std::string		line;

	while(std::getline(stream, line))
		std::cout << line << std::endl;
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		while (*++av)
		{
			std::ifstream	file(*av);
			if (file)
				cat_stream(file);
			else
				std::cerr << "cato9tails: " << *av << ": Failed opening file" << std::endl;
		}
	}
	else
		cat_stream(std::cin);
	return (0);
}
