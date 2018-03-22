/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:51:15 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 09:05:23 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <sstream>

class Brain {

private:
	unsigned int	neurons;

public:
	Brain ();
	~Brain ();

	unsigned int	get_neurons();
	void			set_neurons(unsigned int neurons);
	std::string		identify();
};

#endif
