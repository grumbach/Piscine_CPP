#ifndef STAR_HPP
# define STAR_HPP

# include "AObject.hpp"

class Star: public AObject
{
	public:
		Star(void);
		Star(const Star &);
		Star &operator=(const Star &);
		~Star(void);
		void move(void);
};

std::ostream & operator<<( std::ostream & o, Star const & collidr );

#endif
