#ifndef STAR_HPP
# define STAR_HPP

# include "AObject.hpp"

class Star: public AObject
{
	public:
		Star(void);
		Star(const Star & src);
		Star &operator=(const Star &);
		~Star(void);
		void move(void);
};

#endif
