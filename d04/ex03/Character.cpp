/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:56:38 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 19:31:56 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const & name )
	: name_(name)
{
	int		i = 0;

	while (i < INVENTORY_SIZE)
	{
		this->inventory_[i] = NULL;
		i++;
	}
}

Character::Character( Character const & src )
	: name_(src.getName())
{
	int		i = 0;

	while (i < INVENTORY_SIZE)
	{
		if (i)
			this->inventory_[i] = src.inventory_[i]->clone();
		else
			this->inventory_[i] = NULL;
		i++;
	}
}

Character::Character( void )
	: name_("default")
{
	int		i = 0;

	while (i < INVENTORY_SIZE)
	{
		this->inventory_[i] = NULL;
		i++;
	}
}

Character::~Character()
{
	int		i = 0;

	while (i < INVENTORY_SIZE)
	{
		delete this->inventory_[i];
		i++;
	}
}

Character &				Character::operator=( Character const & rhs )
{
	int		i = 0;

	this->name_ = rhs.getName();

	while (i < INVENTORY_SIZE)
	{
		if (i)
			this->inventory_[i] = rhs.inventory_[i]->clone();
		else
			this->inventory_[i] = NULL;
		i++;
	}
	return *this;
}

/*
** Features
*/

std::string const &		Character::getName() const
{
	return this->name_;
}

void 					Character::equip(AMateria* m)
{
	int		i = 0;

	while (i < INVENTORY_SIZE)
	{
		if (!this->inventory_[i])
		{
			this->inventory_[i] = m;
			break ;
		}
		i++;
	}
}

void 					Character::unequip(int idx)
{
	if (0 <= idx && idx <= INVENTORY_SIZE)
	{
		this->inventory_[idx] = NULL;
	}
}

void 					Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx <= INVENTORY_SIZE)
	{
		this->inventory_[idx]->use(target);
		this->inventory_[idx]->AMateria::use(target);
	}
}
