#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AObject.hpp"

class Enemy: public AObject
{
	public:
		Enemy(void);
		Enemy(const Enemy & src);
		Enemy &operator=(const Enemy & rhs);
		~Enemy(void);
		void move(void);
};

#endif
