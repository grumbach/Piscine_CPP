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
        AObject(const AObject &copy);
        AObject &operator=(const AObject &copy);
        virtual ~AObject(void);
        virtual bool getEnabled(void);
        virtual t_point getPosition(void);
        virtual void setPosition(int y, int x);
        virtual void setEnabled(bool);
        virtual void move(void) = 0;
		char getShape(void) const;

    protected:
        t_point pos;
		bool    enabled;
        char	shape;

};

#endif
