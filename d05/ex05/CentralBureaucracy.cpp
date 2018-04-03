/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:51:57 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/02 17:11:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"

CentralBureaucracy::CentralBureaucracy( void )
{
	for (int i = 0; i < 20; i++) {
		this->_blocks[i] = new OfficeBlock;
		this->_blocks[i]->setIntern(new Intern);
	}
	this->_targets = new std::string[1];
	this->_targets[0] = "";
}

CentralBureaucracy::CentralBureaucracy( CentralBureaucracy const & src )
{
	(void)src;
}

CentralBureaucracy::~CentralBureaucracy()
{
	for (int i = 0; i < 20; i++) {
		delete this->_blocks[i]->getIntern();
		delete this->_blocks[i];
	}
}

CentralBureaucracy & CentralBureaucracy::operator=( CentralBureaucracy const & rhs )
{
	(void)rhs;
	return *this;
}

bool	CentralBureaucracy::setBureaucrat(Bureaucrat * bureaucrat)
{
	for (int i = 0; i < 20; i++) {
		if (this->_blocks[i]->getSigner() == NULL) {
			this->_blocks[i]->setSigner(bureaucrat);
			return true;
		} else if (this->_blocks[i]->getExecutor() == NULL) {
			this->_blocks[i]->setExecutor(bureaucrat);
			return true;
		}
	}
	return false;
}

void	CentralBureaucracy::queueUp(std::string target) {
	std::string	*	temp;
	int i = 0;

	if (target == "")
		return ;
	while (this->_targets[i] != "") {
		i++;
	}
	temp = new std::string[i+2];
	temp[i+1] = "";
	temp[i] = target;
	while (--i >= 0)
		temp[i] = this->_targets[i];
	delete [] this->_targets;
	this->_targets = temp;
}

void	CentralBureaucracy::doBureaucracy(void) {
	int	i = 0;

	while (this->_targets[i] != "") {
		for (int j = 0; j < 20; j++) {
			try
			{
				this->_blocks[j]->doBureaucracy("shrubbery creation", this->_targets[i]);
				this->_blocks[j]->doBureaucracy("presidential pardon", this->_targets[i]);
				this->_blocks[j]->doBureaucracy("robotomy request", this->_targets[i]);
				continue ;
			}
			catch (OfficeBlock::InvalidOfficeBlockException & e)
			{
				break ;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error:" << e.what() << std::endl;
			}
		}
		i++;
	}
}
