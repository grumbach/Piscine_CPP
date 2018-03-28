#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <iostream>
# include <string>

typedef struct {
	int x;
	int y;
} t_point;

class Object
{
    public:
        Object(void);
        Object(const Object &);
        Object &operator=(const Object &);
        ~Object(void);
        bool isEnabled(void);
        t_point getPosition(void);
        void move(void);

    private:
        t_point pos;
		bool    enabled;
};

std::ostream & operator<<( std::ostream & o, Object const & collidr );

#endif