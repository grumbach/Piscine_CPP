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
        bool getEnabled(void);
        t_point getPosition(void);
        void move(void);
        void setPosition(int y, int x);
        void setEnabled(bool);

    private:
        t_point pos;
		bool    enabled;
};

std::ostream & operator<<( std::ostream & o, Object const & collidr );

#endif