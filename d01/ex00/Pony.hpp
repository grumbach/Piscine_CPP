/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:24:13 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/21 20:17:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H

class Pony {

private:
	unsigned int			skin_color;
	unsigned int			hair_color;
	static unsigned int		_living_ponies;

public:
	Pony (int skin, int hair);
	~Pony ();

	static unsigned int		_ponies_alive();
	void					show (void);
};

#endif
