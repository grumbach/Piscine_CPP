#ifndef ROCKET_HPP
# define ROCKET_HPP

# include "AObject.hpp"

class Rocket: public AObject
{
	public:
		Rocket(void);
		Rocket(const Rocket & src);
		Rocket &operator=(const Rocket &);
		~Rocket(void);
		void move(void);
};

#endif
