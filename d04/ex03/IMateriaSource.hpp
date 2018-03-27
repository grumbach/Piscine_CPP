/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:26:01 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:32:57 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

#include "AMateria.hpp"

class IMateriaSource {

public:

	virtual 				~IMateriaSource() {}

	virtual void			learnMateria( AMateria* ) = 0;
	virtual AMateria *		createMateria( std::string const & type ) = 0;

};

#endif
