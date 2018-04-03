/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:49:04 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/03 17:53:47 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

#include <iostream>

class Base {

public:
	virtual ~Base();

};

class A : public Base{ };
class B : public Base{ };
class C : public Base{ };

#endif
