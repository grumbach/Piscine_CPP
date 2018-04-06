/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 23:12:24 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/06 17:32:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span( void )
{
	_vector.reserve(0);
}

Span::Span( unsigned int const & n )
{
	_vector.reserve(n);
}

Span::Span( Span const & src )
{
	*this = src;
}

Span::~Span()
{ }


Span &			Span::operator=( Span const & rhs )
{
	this->_vector = rhs._vector;
	return *this;
}

void			Span::addNumber( const int a )
{
	if (this->_vector.size() >= this->_vector.capacity())
		throw std::out_of_range("Too many items!");
	this->_vector.push_back(a);
}

void			Span::addArray( const int * a, const size_t size )
{
	for (size_t i = 0; i < size; i++)
		this->addNumber(a[i]);
}

size_t			Span::shortestSpan() const
{
	if (this->_vector.size() < 2)
		throw std::logic_error("Not enough minerals!");

	std::vector<int> 	cpy = _vector;
	size_t				span = cpy[0] - cpy[1];

	for (std::vector<int>::iterator it = cpy.begin() ; it != cpy.end() - 1; ++it)
	{
		size_t			tmpSpan = std::abs(*it - *(it + 1));
		if (tmpSpan < span)
			span = tmpSpan;
	}
	return span;
}

size_t			Span::longestSpan() const
{
	if (this->_vector.size() < 2)
		throw std::logic_error("Not enough minerals!");

	return std::abs(*std::min_element(_vector.begin(), _vector.end()) - \
		*std::max_element(_vector.begin(), _vector.end()));
}
