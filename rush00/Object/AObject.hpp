#ifndef AOBJECT_HPP
# define AOBJECT_HPP

# include <iostream>
# include <string>

typedef struct {
	int x;
	int y;
} t_point;

class AObject
{
    public:
        AObject(void);
        AObject(const AObject &);
        AObject &operator=(const AObject &);
        ~AObject(void);
        virtual bool getEnabled(void);
        virtual t_point getPosition(void);
        virtual void setPosition(int y, int x);
        virtual void setEnabled(bool);
        void move(void);

    protected:
        t_point pos;
		bool    enabled;
};

std::ostream & operator<<( std::ostream & o, AObject const & collidr );

#endif