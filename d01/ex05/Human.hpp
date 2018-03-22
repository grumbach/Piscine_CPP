/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:51:32 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:11:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

#include "Brain.hpp"

class Human {

private:
	Brain		brain;

public:
	Human ();
	~Human ();

	std::string		identify();
	Brain			&getBrain();
};

#endif
