/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 23:08:50 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/06 17:21:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <algorithm>
#include <vector>

class Span {

public:

	Span( void );
	Span( unsigned int const & N );
	Span( Span const & src );
	virtual ~Span();

	Span &			operator=( Span const & rhs );

	void			addNumber( const int a );
	void			addArray( const int * a, const size_t size );
	void			addVector( const int a );
	size_t			shortestSpan() const;
	size_t			longestSpan() const;

private:

	std::vector<int>	_vector;

};

#endif
