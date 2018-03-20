/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:46:24 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/20 04:00:31 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact()
{ }

Contact::~Contact(void)
{ }


void		Contact::fill_info()
{
	std::cout << "firstname: ";
	std::getline(std::cin, this->firstname);
	std::cout << "lastname: ";
	std::getline(std::cin, this->lastname);
	std::cout << "nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "login: ";
	std::getline(std::cin, this->login);
	std::cout << "postal_address: ";
	std::getline(std::cin, this->postal_address);
	std::cout << "email_address: ";
	std::getline(std::cin, this->email_address);
	std::cout << "phone_number: ";
	std::getline(std::cin, this->phone_number);
	std::cout << "birthday_date: ";
	std::getline(std::cin, this->birthday_date);
	std::cout << "favorite_meal: ";
	std::getline(std::cin, this->favorite_meal);
	std::cout << "underwear_color: ";
	std::getline(std::cin, this->underwear_color);
	std::cout << "darkest_secret: ";
	std::getline(std::cin, this->darkest_secret);
}

void		Contact::show_info() const
{
	std::cout << "firstname: ";
	std::cout << this->firstname << std::endl;
	std::cout << "lastname: ";
	std::cout << this->lastname << std::endl;
	std::cout << "nickname: ";
	std::cout << this->nickname << std::endl;
	std::cout << "login: ";
	std::cout << this->login << std::endl;
	std::cout << "postal_address: ";
	std::cout << this->postal_address << std::endl;
	std::cout << "email_address: ";
	std::cout << this->email_address << std::endl;
	std::cout << "phone_number: ";
	std::cout << this->phone_number << std::endl;
	std::cout << "birthday_date: ";
	std::cout << this->birthday_date << std::endl;
	std::cout << "favorite_meal: ";
	std::cout << this->favorite_meal << std::endl;
	std::cout << "underwear_color: ";
	std::cout << this->underwear_color << std::endl;
	std::cout << "darkest_secret: ";
	std::cout << this->darkest_secret << std::endl;
}

void		Contact::show_short() const
{
	if (this->firstname.length() <= 10)
		std::cout << std::setw(10) << this->firstname << "|";
	else
	{
		for (size_t i = 0; i < 9; i++)
			std::cout << this->firstname[i];
		std::cout << ".|";
	}
	if (this->lastname.length() <= 10)
		std::cout << std::setw(10) << this->lastname << "|";
	else
	{
		for (size_t i = 0; i < 9; i++)
			std::cout << this->lastname[i];
		std::cout << ".|";
	}
	if (this->nickname.length() <= 10)
		std::cout << std::setw(10) << this->nickname << std::endl;
	else
	{
		for (size_t i = 0; i < 9; i++)
			std::cout << this->nickname[i];
		std::cout << "."<< std::endl;
	}
}
