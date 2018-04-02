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

#include "CentralBureaucracy.hpp"

int			main( void )
{
	CentralBureaucracy	boring;
	Bureaucrat			a("a", 42);
	Bureaucrat			b("b", 42);

	boring.feed_company(&a);
	boring.feed_company(&b);

	std::cout << "bored, not doing the rest..." << std::endl;
	return (0);
}
