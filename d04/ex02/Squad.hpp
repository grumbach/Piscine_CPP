/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:48:37 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:49:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

typedef struct      s_unit
{
	ISpaceMarine	*unit;
	struct s_unit	*next;
}                   t_unit;

class Squad: public ISquad {

public:

	Squad( void );
	Squad( Squad const & src );
	~Squad( void );
	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);
	bool alreadyHas(ISpaceMarine *marine, t_unit *head);
	void destroyChilds(void);
	void cloneFrom(const Squad &src);
	Squad& operator=(Squad const & rhs);

private:

	t_unit *_list;
	int _count;

};

std::ostream & operator<<( std::ostream & o, Squad const & i );

#endif
