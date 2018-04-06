/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:34:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/06 18:17:49 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

private:

	typedef		std::stack<T> super;

public:

	MutantStack( void )
	{ }

	MutantStack( MutantStack const & src ) : super( src )
	{ }

	virtual ~MutantStack()
	{ }

	using super::operator=;
	typedef typename super::container_type::iterator	iterator;

	iterator begin()
	{
		return super::c.begin();
	}

	iterator end()
	{
		return super::c.end();
	}
};

#endif
