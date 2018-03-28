/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:39:07 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/28 11:46:02 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

#include <iostream>
#include <ctime>
#include <fstream>

class Logger {

private:
	std::string	log_file_name;

	void		logToConsole(std::string const & str) const;
	void		logToFile(std::string const & str) const;
	std::string	makeLogEntry(std::string const & str) const;

public:
	Logger (std::string const & str);
	~Logger ();

	void		log(std::string const & dest, std::string const & message) const;
};

#endif
