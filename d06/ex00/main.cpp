/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:38:24 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/03 17:22:17 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>

int			main(int ac, char **av)
{
	double				d;

	if (ac < 2)
	{
		std::cout << "Please feed me numbers!!" << std::endl;
		return (0);
	}

	while (*++av)
	{
		std::string	str(*av);

		//char case
		if (str.length() == 1 && !isdigit(str[0]))
			d = str[0];
		else
		{
			try
			{
				d = std::stod(*av);
			}
			catch (std::exception & e)
			{
				std::cerr << "Invalid Input: " << e.what() << std::endl;
				return (-1);
			}
		}

		//nan inf etc cases
		if (*(*av + 1) && !isdigit(*(*av + 1)))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		//normal behavior
		else
		{
			if (isprint(static_cast<int>(d)))
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		}

		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	return (0);
}

/*
Examples of char literal values: ’c’, ’a’, ... To simplify, please note that : non dis- playable characters can’t be passed as a parameter to your program, and if a conversion to char is not displayable, output a notification instead.
Examples of int literal values: 0, -42, 42, ...
Examples of float literal values: 0.0f, -4.2f, 4.2f, ... You will also accept these
pseudo literals as well, you know, for science: -inff, +inff and nanf.
Examples of double literal values: 0.0, -4.2, 4.2, ... You will also accept these
pseudo literals as well, you know, for... fun: -inf, +inf and nan.
*/
