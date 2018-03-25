/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:31:42 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/25 20:33:42 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

/*
** http://www-inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
*/

#include <iostream>
#include <cmath>

class Fixed {

public:

	Fixed( void );
	Fixed( const int integer );
	Fixed( const float flt );
	Fixed( Fixed const & src );
	~Fixed();
	Fixed &					operator= ( Fixed const & rhs );

	bool					operator< (Fixed const & rhs) const;
	bool					operator> (Fixed const & rhs) const;
	bool					operator<=(Fixed const & rhs) const;
	bool					operator>=(Fixed const & rhs) const;
	bool					operator==(Fixed const & rhs) const;
	bool					operator!=(Fixed const & rhs) const;

	Fixed 					operator+ (Fixed const & rhs) const;
	Fixed 					operator- (Fixed const & rhs) const;
	Fixed 					operator/ (Fixed const & rhs) const;
	Fixed 					operator* (Fixed const & rhs) const;

	Fixed &					operator++();
	Fixed &					operator--();
	Fixed 					operator++(int);
	Fixed 					operator--(int);

	int						getRawBits( void ) const;
	void					setRawBits( int const raw );
	float					toFloat( void ) const;
	int						toInt( void ) const;

	static Fixed &			max(Fixed & a, Fixed & b);
	static Fixed &			min(Fixed & a, Fixed & b);
	static Fixed const &	max(Fixed const & a, Fixed const & b);
	static Fixed const &	min(Fixed const & a, Fixed const & b);

private:
	static const int		_binary_point = 8;
	int						raw_value;

};


std::ostream &				operator<<( std::ostream & o, Fixed const & i );

#endif
