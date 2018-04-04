/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:37:17 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/04 16:57:57 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {

public:

	Array( void )
		: _array(NULL)
		, _size(0)
	{ }

	Array( unsigned int n )
		: _array(new T[n])
		, _size(n)
	{ bzero(this->_array, this->_size * sizeof(T)); }

	Array( Array const & src ) { *this = src; }

	virtual ~Array() { delete [] this->_array; }

	size_t		size( void ) const { return (this->_size); }

	T &			operator[]( size_t index ) const
	{
		if (this->_size <= index)
			throw std::exception();
		return this->_array[index];
	}

	Array &		operator=( Array const & rhs )
	{
		size_t	array_size = rhs.size();
		this->_array = new T[array_size];

		for (size_t i = 0; i < array_size; i++)
			this->_array[i] = rhs[i];
		return *this;
	}

private:

	T			*_array;
	size_t		_size;

};
