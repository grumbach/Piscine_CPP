/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:46:44 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:09:13 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IASTEROID_H
# define IASTEROID_H

class DeepCoreMiner;
class StripMiner;

class IAsteroid {

public:

	virtual ~IAsteroid() {}
	virtual std::string		beMined(DeepCoreMiner *) const = 0;
	virtual std::string		beMined(StripMiner *) const = 0;

};

#endif
