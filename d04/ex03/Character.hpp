/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:38:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 11:32:24 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

# define INVENTORY_SIZE			4

class Character : public ICharacter {

public:

	Character( std::string const & name );
	Character( Character const & src );
	~Character();

	Character &		operator=( Character const & rhs );

	virtual std::string const &		getName() const;
	virtual void 					equip(AMateria* m);
	virtual void 					unequip(int idx);
	virtual void 					use(int idx, ICharacter& target);

	AMateria *			inventory_[INVENTORY_SIZE];

private:

	Character( void );

	std::string			name_;

};

#endif
