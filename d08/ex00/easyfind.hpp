/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:18:49 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/05 22:29:55 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <vector>
#include <algorithm>

template < typename T >
typename T::iterator		easyfind(T &a, int b)
{
	typename T::iterator	it;

	if ((it = std::find(a.begin(), a.end(), b)) == a.end())
		throw std::exception();
	return it;
}

#endif

/*
Make a template function called easyfind, templated on a type T, that takes a T and an int.
Assume the T is a container of int, and find the first occurence of the second param- eter in the first parameter.
If it can’t be found, handle the error either using an exception or using an error return value. Take ideas from how standard containers work.
Of course, you will provide a main function that tests it thoroughly.
*/
