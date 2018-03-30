#ifndef ROCKET_HPP
# define ROCKET_HPP

# include "AObject.hpp"

class Rocket: public AObject
{
	public:
		Rocket(void);
		Rocket(const Rocket & src);
		Rocket &operator=(const Rocket & rhs);
		~Rocket(void);
		void move(void);
};

#endif
