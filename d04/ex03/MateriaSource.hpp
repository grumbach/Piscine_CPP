/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:27:16 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:33:49 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

# define SOURCE_SIZE			4

class MateriaSource : public IMateriaSource {

public:

	MateriaSource( void );
	MateriaSource( MateriaSource const & src );
	~MateriaSource();

	MateriaSource &		operator=( MateriaSource const & rhs );

	void				learnMateria( AMateria * m );
	AMateria *			createMateria( std::string const & type );

	AMateria *		inventory_[SOURCE_SIZE];
};

#endif
