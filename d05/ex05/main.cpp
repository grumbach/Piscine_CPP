/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:35:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 17:09:29 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

std::string genRandomName(void) {
    std::string s(10, ' ');
    static const char voyel[] =
        "aeiouy";
	static const char consone[] =
        "bcdfghjklmnpqrstvwxz";

    for (int i = 0; i < 10; ++i) {
        s[i++] = consone[rand() % (sizeof(consone) - 1)];
		s[i] = voyel[rand() % (sizeof(voyel) - 1)];
    }
    return s;
}

int		main(void)
{
	CentralBureaucracy	central;
	Bureaucrat			*bureaucrat;

	for (int i = 0; i < 2; i++) {
		bureaucrat = new Bureaucrat(genRandomName(), 1);
		if (central.setBureaucrat(bureaucrat) == false)
			break ;
	}
	for (int i = 0; i < 4; i++) {
		central.queueUp(genRandomName());
	}
	central.doBureaucracy();
	return (0);
}
