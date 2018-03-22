/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:52:32 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/22 16:03:46 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

#include <iostream>
#include <map>

class Human {

private:
	void	meleeAttack(std::string const & target) const;
	void	rangedAttack(std::string const & target) const;
	void	intimidatingShout(std::string const & target) const;

public:
	void	action(std::string const & action_name, std::string const & target) const;
	Human ();
	~Human ();
};

#endif
