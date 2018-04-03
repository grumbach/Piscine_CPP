/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:32:37 by agrumbac          #+#    #+#             */
/*   Updated: 2018/04/03 17:46:24 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	std::string		s1;
	int 			n;
	std::string		s2;
};

void		*serialize( void )
{
	static const std::string	random_data[10] =
	{
		"c++casts",
		"are sooo",
		"weak and",
		" frail  ",
		"compared",
		"to casts",
		"in pure ",
		"C! where",
		" is my  ",
		"(void*)?"
	};

	Data	*data = new Data();
	data->s1 = random_data[std::rand() % 10];
	data->n = std::rand();
	data->s2 = random_data[std::rand() % 10];

	return data;
}

Data		*deserialize( void * raw )
{
	return reinterpret_cast<Data*>(raw);
}

int			main( void )
{
	std::srand(std::time(nullptr));

	void	*tutu = serialize();

	Data	*tata = deserialize(tutu);

	std::cout << "data->s1: " << tata->s1 << std::endl;
	std::cout << "data->n: " << tata->n << std::endl;
	std::cout << "data->s2: " << tata->s2 << std::endl;
	return (0);
}
