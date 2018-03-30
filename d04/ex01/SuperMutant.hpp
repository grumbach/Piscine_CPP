/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:42:49 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:43:03 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

	SuperMutant(SuperMutant const & src);
	SuperMutant(void);
	~SuperMutant(void);
	void takeDamage(int damage);

	SuperMutant & operator=( SuperMutant const & rhs );

};

#endif
