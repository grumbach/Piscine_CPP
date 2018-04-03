/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:35:23 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 17:01:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int		main(void)
{
	Intern  	someRandomIntern;
	Bureaucrat	boss("Bill Gates", 1);
	Form   		*f;

	f = someRandomIntern.makeForm("robotomy request", "Windows");

	if (f) {
		boss.signForm(*f);
		boss.executeForm(*f);
	}
	delete f;
	return (0);
}
