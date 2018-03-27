/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:52:49 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:33:45 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	int		i = 0;

	while (i < SOURCE_SIZE)
	{
		this->inventory_[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	int		i = 0;

	while (i < SOURCE_SIZE)
	{
		this->inventory_[i] = src.inventory_[i]->clone();
		i++;
	}
}

MateriaSource::~MateriaSource()
{
	int		i = 0;

	while (i < SOURCE_SIZE)
	{
		delete this->inventory_[i];
		i++;
	}
}


MateriaSource &		MateriaSource::operator=( MateriaSource const & rhs )
{
	int		i = 0;

	while (i < SOURCE_SIZE)
	{
		delete inventory_[i];
		this->inventory_[i] = rhs.inventory_[i]->clone();
		i++;
	}
	return *this;
}

/*
** Features
*/

void				MateriaSource::learnMateria( AMateria * m )
{
	int		i = 0;

	while (i < SOURCE_SIZE)
	{
		if (!this->inventory_[i])
		{
			this->inventory_[i] = m;
			break ;
		}
		i++;
	}
}

AMateria *			MateriaSource::createMateria( std::string const & type )
{
	int		i = 0;

	while (i < SOURCE_SIZE)
	{
		if (this->inventory_[i] && this->inventory_[i]->getType() == type)
			return this->inventory_[i]->clone();
		i++;
	}
	return NULL;
}
