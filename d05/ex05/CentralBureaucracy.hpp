/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:49:57 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 14:14:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY
# define CENTRALBUREAUCRACY

#include "OfficeBlock.hpp"

# define OFFICES			20

class CentralBureaucracy {

public:

	CentralBureaucracy( void );
	CentralBureaucracy( CentralBureaucracy const & src );
	virtual ~CentralBureaucracy();

	CentralBureaucracy &	operator=( CentralBureaucracy const & rhs );

	bool					feed_company( Bureaucrat * livestock);

private:

	Intern			_interns[OFFICES];
	OfficeBlock		_offices[OFFICES];

};

#endif
