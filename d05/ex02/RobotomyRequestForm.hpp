/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:39:40 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/29 16:44:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm( std::string const & target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	~RobotomyRequestForm();

	RobotomyRequestForm &			operator=( RobotomyRequestForm const & rhs );

	bool			execute( Bureaucrat const & executor ) const;

};

#endif
