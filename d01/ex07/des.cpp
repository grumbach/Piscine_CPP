/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:49:26 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 12:12:55 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int		errors(int err)
{
	std::cerr << "des: ";

	if (err == 1)
		std::cerr << "failed to read file";
	if (err == 2)
	{
		std::cerr << "invalid number of parameters";
		std::cerr << std::endl << "usage: [valid file] [string to replace] [new string]";
	}
	if (err == 3)
		std::cerr << "failed to write file";

	std::cerr << std::endl;
	return (-1);
}

int		main(int ac, char **av)
{
	std::string		buffer;

	//check args
	if (ac != 4)
		return errors(2);
	std::string		old_word(av[2]);
	std::string		new_word(av[3]);
	//read
	std::ifstream	ifs(av[1]);
	if (!ifs.is_open())
		return errors(1);
	//write
	std::ofstream	ofs(std::string(av[1]) + ".replace");
	if (!ofs.is_open())
		return errors(3);

	size_t			len = old_word.length();
	while (std::getline(ifs, buffer))
	{
		while (true)
		{
			size_t	pos = buffer.find(old_word);
			if (pos != std::string::npos)
				buffer.replace(pos, len, new_word);
			else
				break ;
		}
		ofs << buffer << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
