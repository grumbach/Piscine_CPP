/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:47:32 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 12:47:49 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine {

public:

	TacticalMarine( void );
	TacticalMarine( TacticalMarine const & src );
	~TacticalMarine( void );
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;
	ISpaceMarine* clone( void ) const;

	TacticalMarine& operator=(TacticalMarine const & rhs);

};

std::ostream & operator<<( std::ostream & o, TacticalMarine const & tm );

#endif
