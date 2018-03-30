#ifndef PILOT_HPP
# define PILOT_HPP

# include "AObject.hpp"
# include "../Collection/RocketsCollection.hpp"

class Pilot: public AObject
{
	public:
		Pilot(void);
		Pilot(const Pilot &);
		Pilot &operator=(const Pilot &);
		~Pilot(void);
		void				move(void);
		void				setDirection(char dir);
		void				shoot(void);
		RocketsCollection	&getRockets(void);

	private:
		char				dir;
		RocketsCollection	rockets;
		void				setDir(char dir);
};

#endif
