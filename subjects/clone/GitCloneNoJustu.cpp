/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GitCloneNoJustu.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:56:39 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 15:02:59 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

# define LINES_TO_REMOVE			12


int		str_ends_with(const char * str, const char * suffix)
{
	if( str == NULL || suffix == NULL )
	return 0;

	size_t str_len = strlen(str);
	size_t suffix_len = strlen(suffix);

	if(suffix_len > str_len)
	return 0;

	return 0 == strncmp( str + str_len - suffix_len, suffix, suffix_len );
}

void	cat_stream(std::istream &stream, std::string const &name)
{
	std::string				line;

	//read file in a string
	std::string				file_string((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
	std::istringstream		string_stream(file_string);

	//open file to write
	std::ofstream			fileout(name);
	if (!fileout.is_open())
	{
		std::cerr << "GitCloneNoJustu: " << name << ": Failed opening file" << std::endl;
		return ;
	}

	//write the string to file
	size_t i = 0;
	while(std::getline(string_stream, line))
	{
		//check for header
		if (!(i < LINES_TO_REMOVE && (line[0] == '/' || line[0] == 0 || (name.find("Makefile") != std::string::npos && line[0] == '#'))))
		{
			fileout << line << std::endl;
			i = LINES_TO_REMOVE;
		}
		i++;
	}

	//done
	fileout.close();
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		while (*++av)
		{
			std::ifstream	file(*av);
			if (file.is_open())
				cat_stream(file, *av);
			else
				std::cerr << "GitCloneNoJustu: " << *av << ": Failed opening file" << std::endl;
		}
	}
	else
		std::cerr << "GitCloneNoJustu: please provide at least one [filename]" << std::endl;
	return (0);
}
