/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crappy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:06:09 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 11:41:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

static int			add(Contact contacts[MAX_CONTACTS], const int index)
{
	if (index >= MAX_CONTACTS)
	{
		std::cout << "[!] max contacts reached, pay for more" << std::endl;
		return (0);
	}
	contacts[index].fill_info();
	return (1);
}

static void			search(const Contact contacts[MAX_CONTACTS], const int index)
{
	int				i;

	i = 0;
	std::cout << std::left << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::right << std::endl;
	while (i < index)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].show_short();
		i++;
	}
	if (i)
	{
		std::cout << "index desired: ";
		std::cin >> i;
		if (std::cin.fail())
		{
			i = -1;
			std::cin.clear();
		}
		if (i >= 0 && i < index)
			contacts[i].show_info();
		else
			std::cout << "[!] invalid index" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int					main(void)
{
	std::string		known_commands[3] = {"ADD", "SEARCH", "EXIT"};
	std::string		command;
	Contact			contacts[MAX_CONTACTS];
	int				index;

	index = 0;
	while (true)
	{
		std::cout << "\e[2m" << "crappy" << "\e[0m" << " awesome phonebook$> ";
		if (!std::getline(std::cin, command))
			break;
		if (command.compare(known_commands[0]) == 0)
			index += add(contacts, index);
		else if (command.compare(known_commands[1]) == 0)
			search(contacts, index);
		else if (command.compare(known_commands[2]) == 0)
			break;
	}
	return (0);
}
