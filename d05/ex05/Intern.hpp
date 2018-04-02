/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:00 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/30 16:43:48 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "Form.hpp"

class Intern {

public:

	Intern( void );
	Intern( Intern const & src );
	~Intern();

	Intern &	operator=( Intern const & rhs );

	Form		*makeForm( std::string const & form_type, std::string const & target ) const;

};

#endif
