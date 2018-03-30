/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:43:25 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:43:35 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion(RadScorpion const & src);
	RadScorpion(void);
	~RadScorpion(void);

	RadScorpion & operator=( RadScorpion const & rhs );

};

#endif
