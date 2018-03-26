/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:32:04 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/26 11:58:41 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** Constructors Destructors
*/

Fixed::Fixed( void )
	: raw_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( const int integer )
	: raw_value(integer << Fixed::_binary_point)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float flt )
	: raw_value(roundf(flt * (1 << Fixed::_binary_point)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/*
** Operator Overloads
** • Assignation operator =
** • Six comparison operators : >, <, >=, <=, == and !=
** • Four arithmetic operators : +, -, *, and /
** • The pre-increment, post-increment, pre-decrement and post-decrement
**   operators, that will increment or decrement the fixed point value from
**   the smallest repre- sentable ε such as 1 + ε > 1.
** • Stream feeding operator <<
*/

Fixed &					Fixed::operator= ( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	this->raw_value = rhs.getRawBits();

	return *this;
}

//// Six comparison operators : >, <, >=, <=, == and !=

bool					Fixed::operator< (Fixed const & rhs) const
{
	return this->raw_value < rhs.getRawBits();
}

bool					Fixed::operator> (Fixed const & rhs) const
{
	 return this->raw_value > rhs.getRawBits();
}

bool					Fixed::operator<=(Fixed const & rhs) const
{
	 return !(this->raw_value > rhs.getRawBits());
}

bool					Fixed::operator>=(Fixed const & rhs) const
{
	 return !(this->raw_value < rhs.getRawBits());
}

bool					Fixed::operator==(Fixed const & rhs) const
{
	return this->raw_value == rhs.getRawBits();
}

bool					Fixed::operator!=(Fixed const & rhs) const
{
	return !(this->raw_value == rhs.getRawBits());
}

//// Four arithmetic operators : +, -, *, and /

Fixed 					Fixed::operator+ (Fixed const & rhs) const
{
	Fixed				result;

	result.raw_value = this->raw_value + rhs.getRawBits();
	return result;
}

Fixed 					Fixed::operator- (Fixed const & rhs) const
{
	Fixed				result;

	result.raw_value = this->raw_value - rhs.getRawBits();
	return result;
}

Fixed 					Fixed::operator/ (Fixed const & rhs) const
{
	Fixed				result;
	long				overflow_guard;

	overflow_guard = this->raw_value;
	overflow_guard <<= Fixed::_binary_point;
	overflow_guard /= rhs.getRawBits();
	result.raw_value = overflow_guard;
	return result;
}

Fixed 					Fixed::operator* (Fixed const & rhs) const
{
	Fixed				result;
	long				overflow_guard;

	overflow_guard = this->raw_value;
	overflow_guard *= rhs.getRawBits();
	overflow_guard >>= Fixed::_binary_point;
	result.raw_value = overflow_guard;
	return result;
}

//// The pre-increment, post-increment, pre-decrement and post-decrement operators
// ++prefix
Fixed &					Fixed::operator++()
{
	this->raw_value++;
	return *this;
}

Fixed &					Fixed::operator--()
{
	this->raw_value--;
	return *this;
}

// postfix++
Fixed 					Fixed::operator++(int)
{
	Fixed				old_value;

	old_value = *this;
	this->raw_value++;

	return old_value;
}

Fixed 					Fixed::operator--(int)
{
	Fixed				old_value;

	old_value = *this;
	this->raw_value--;

	return old_value;
}

/*
** min max
*/

Fixed &			Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed &			Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}


/*
** Data getter setter
*/

float					Fixed::toFloat( void ) const
{
	return this->raw_value / (float)(1 << Fixed::_binary_point);
}

int						Fixed::toInt( void ) const
{
	return this->raw_value >> Fixed::_binary_point;
}


int						Fixed::getRawBits( void ) const
{
	return this->raw_value;
}

void					Fixed::setRawBits( int const raw )
{
	this->raw_value = raw;
}



//// Stream feeding operator <<

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();

	return o;
}
