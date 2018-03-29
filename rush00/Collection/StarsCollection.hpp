#ifndef STARSCOLLECTION_HPP
# define STARSCOLLECTION_HPP

# include <iostream>
# include <string>
# include "ACollection.hpp"
# include "../Object/Star.hpp"

class StarsCollection
{
    public:
        StarsCollection(void);
        StarsCollection(const StarsCollection &);
        StarsCollection &operator=(const StarsCollection &);
        ~StarsCollection(void);
        void updateObjects(void);
        virtual void    setBounds(Bounds newBounds);
        virtual int     getSize(void) const;
        virtual AObject *get(int index) const;
    private:
        Bounds  bounds;
        int     size;
        AObject *data;
};

std::ostream & operator<<( std::ostream & o, StarsCollection const & coll );

#endif