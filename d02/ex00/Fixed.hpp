/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:31:42 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/24 18:36:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

/*
** http://www-inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
*/

#include <iostream>

class Fixed {

public:

	Fixed( void );
	Fixed( int const n );
	Fixed( Fixed const & src );
	~Fixed();
	Fixed &					operator=( Fixed const & rhs );

	int						getRawBits( void ) const;
	void					setRawBits( int const raw );

private:
	static const int		_binary_point = 8;
	int						raw_value;

};


std::ostream &				operator<<( std::ostream & o, Fixed const & i );

#endif
