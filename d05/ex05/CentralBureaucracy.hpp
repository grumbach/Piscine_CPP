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

#ifndef CENTRALBUREAUCRACY_H
# define CENTRALBUREAUCRACY_H

#include "Form.hpp"
#include "OfficeBlock.hpp"

class CentralBureaucracy {

public:

	CentralBureaucracy( void );
	CentralBureaucracy( CentralBureaucracy const & src );
	~CentralBureaucracy();
	CentralBureaucracy &	operator=( CentralBureaucracy const & rhs );

	void	queueUp(std::string target);
	void	doBureaucracy(void);
	bool	setBureaucrat(Bureaucrat * bureaucrat);

private:
	OfficeBlock *	_blocks[20];
	std::string	*	_targets;

};

#endif
