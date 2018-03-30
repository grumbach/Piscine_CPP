/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:53:45 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:53:58 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy {

protected:

	int hp;
	std::string const & type;

public:

	Enemy(Enemy const & src);
	Enemy(int hp, std::string const & type);
	virtual ~Enemy(void);
	std::string getType(void) const;
	int getHP(void) const;

	virtual void takeDamage(int damage);

	Enemy & operator=( Enemy const & rhs );

};

#endif
