/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:39:34 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/23 18:47:04 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

// private

void		Logger::logToConsole(std::string const & str) const
{
	std::cout << str << std::endl;
}

void		Logger::logToFile(std::string const & str) const
{
	std::ofstream	fileout(this->log_file_name, std::ios_base::app);

	fileout << str << std::endl;
	fileout.close();
}

std::string	Logger::makeLogEntry(std::string const & str) const
{
	char		buf[100];
	std::time_t	t = std::time(nullptr);

	if (!std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&t)))
		return (std::string("[error getting time]" + str));
	return (std::string(buf) + str);
}

// public

Logger::Logger (std::string const & str)
	: log_file_name(str)
{ }

Logger::~Logger ()
{ }

void		Logger::log(std::string const & dest, std::string const & message) const
{
	std::string str = this->makeLogEntry(message);

	typedef void	(Logger::*log_method)(std::string const &) const;
	std::map <std::string, log_method> mapping;
	mapping.insert(std::make_pair("console" , &Logger::logToConsole));
	mapping.insert(std::make_pair("file" , &Logger::logToFile));

	log_method chosen = mapping[dest];
	(this->*chosen)(str);
}
